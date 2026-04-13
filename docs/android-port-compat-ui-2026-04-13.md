# Continuidade do Port Android: Verificação pós-git pull (2026-04-13)

## Resumo

Após o `git pull` no branch `mobile`, foi realizada uma auditoria de consistência entre:

- código-fonte atual,
- checklist de progresso em `ANDROID_PORT.md`,
- e o relatório anterior de compatibilidade de UI/texto.

O objetivo foi confirmar o que realmente já está implementado no port Android e atualizar o status sem marcar itens de forma prematura.

## Evidências verificadas no código

### Compatibilidade Win32/UI em Android

Arquivo validado: `Main/source/Platform/AndroidWin32Compat.h`

Foram confirmados no código:

- `GWL_WNDPROC` e `GWL_USERDATA`
- mensagens IME (`WM_IME_*`) e `IMN_SETOPENSTATUS`
- stubs `ImmGetCompositionWindow` / `ImmSetCompositionWindow`
- `OffsetRect`
- `_vsntprintf`
- `GetKeyState`

Conclusão: o bloco de compatibilidade de UI/IME descrito no relatório de 2026-04-12 está efetivamente presente.

### Limpeza de módulo Win32 puro no build Android

Arquivo validado: `Main/android/app/src/main/cpp/CMakeLists.txt`

- `CBTMessageBox.cpp` não está listado nas fontes Android.

Conclusão: a remoção do módulo Win32-only do pipeline Android está aplicada.

### DirectSound guard no Android

Arquivo validado: `Main/source/DSplaysound.cpp`

- implementação protegida por `#ifndef __ANDROID__`.

Conclusão: comportamento esperado para excluir DirectSound no Android está ativo.

### Include chain do backend GLES no util OpenGL

Arquivos validados:

- `Main/source/ZzzOpenglUtil.cpp`
- `Main/source/StdAfx.h`

Foi confirmado:

- `ZzzOpenglUtil.cpp` inclui `stdafx.h` como primeiro include;
- `StdAfx.h` inclui `Platform/GLFixedFunctionStubs.h`.

Conclusão: item de verificação de includes para `ZzzOpenglUtil.cpp` pode ser tratado como concluído.

## Pendências ainda abertas (confirmadas)

### Build / toolchain

- Build limpo `./gradlew assembleDebug` ainda não comprovado como verde fim-a-fim nesta auditoria.

### Render e gameplay visual

- `ZzzBMD.cpp` (modelos 3D)
- `ZzzLodTerrain.cpp` (terrain)
- `ZzzEffect*.cpp` (efeitos/partículas)

### Input / texto

- `Input.cpp` ainda usa `GetCursorPos/ScreenToClient` (não migrado para caminho Android explícito no arquivo).
- soft keyboard (`ANativeActivity_showSoftInput`) não encontrado no código auditado.
- `CGMFontLayer.cpp` ainda contém trecho GDI (`GetTextMetricsW`, `GetFontData`) como pendência do checklist.

### Assets/áudio

- pasta `Main/dependencies/include/minimp3/` não encontrada.
- fonte em `Main/android/app/src/main/assets/fonts/NotoSans-Regular.ttf` não encontrada.

### File I/O residual

- `Main/source/ZzzAI.cpp` ainda possui uso de `CreateFile`.

### Downloader (1ª execução)

Arquivos existem:

- `Main/source/Platform/GameDownloader.h`
- `Main/source/Platform/GameDownloader.cpp`

Status funcional atual do downloader:

- há estrutura básica (`IsDataReady`, `DownloadAll`, `SetServerURL`),
- há lista mínima de arquivos obrigatórios,
- porém o método de download HTTP ainda está em placeholder e retorna falha,
- validação CRC/extracão completa ainda não finalizada.

Conclusão: manter Fase 7 como em andamento.

## Atualizações aplicadas no checklist principal

Arquivo atualizado: `ANDROID_PORT.md`

Foram ajustados:

- marcação concluída de `ZzzOpenglUtil.cpp` (verificação de includes);
- marcação concluída de `DSplaysound.cpp` guardado para Android;
- inclusão explícita dos shims UI/IME e dos shims residuais (`OffsetRect`, `_vsntprintf`, `GetKeyState`) como concluídos em Win32 replacements;
- inclusão da remoção de `CBTMessageBox.cpp` no `CMakeLists.txt` Android como concluída;
- atualização da linha de "Última atualização" para `2026-04-13`.

## Próximo passo recomendado

1. Rodar `./gradlew assembleDebug` e capturar o primeiro erro atual (se houver).
2. Fechar pendências de `Input.cpp` + soft keyboard.
3. Fechar `CGMFontLayer.cpp` Android path + bundle da fonte TTF.
4. Avançar no `GameDownloader.cpp` substituindo o placeholder HTTP por implementação real e integrando CRC.
