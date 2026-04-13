# Mu Cross Engine

## Visao geral

Repositorio principal do cliente MU Online baseado em C++ com foco no `Main` legado de Windows e continuidade de portabilidade para Android via APK nativo.

## Estrutura principal

- `Main/`: codigo-fonte principal do cliente, solucao Visual Studio e projeto Android.
- `Main/source/`: codigo legado do cliente, incluindo renderizacao, rede, UI e sistemas do jogo.
- `Main/android/`: projeto Gradle/CMake do port Android.
- `Util/`: bibliotecas utilitarias e dependencias auxiliares do cliente.
- `docs/`: documentacao tecnica do repositorio em pt-BR.

## Estado atual do port Android

O projeto ja possui base Android com:

- Projeto Gradle.
- App Android com `minSdk 26`.
- Build nativo via CMake.
- Backend OpenGL ES 3.0.
- Camada de compatibilidade Win32 para grande parte do cliente legado.

Os principais bloqueios conhecidos no momento sao:

- `JAVA_HOME` nao configurado no ambiente atual, impedindo rodar `gradlew assembleDebug`.
- Downloader de assets ainda sem transporte HTTP final.
- Integracao completa de teclado virtual/IME Android ainda pendente.
- O port ainda depende de iteracoes de compatibilidade em partes da UI legada e de modulos Win32 restantes.

## Build

### Windows

- Solucao: `Main/Main.sln`
- Plataforma principal: `Win32`

### Android

- Projeto Gradle: `Main/android`
- Entrada nativa: `Main/android/app/src/main/cpp/android_main.cpp`
- Manifesto: `Main/android/app/src/main/AndroidManifest.xml`

## Changelog

### 2026-04-12

- Expandida a camada `AndroidWin32Compat.h` para suportar melhor caixas de texto, mensagens de janela, foco, IME e constantes Win32 usadas pela UI legada no Android.
- Adicionada documentacao tecnica da etapa em `docs/android-port-compat-ui-2026-04-12.md`.
- Registrado o estado atual e os bloqueios do port Android neste README.
- Preparado um JDK portatil local para o projeto, configurado o cache local do Gradle e levado o build Android ate a compilacao nativa do NDK.
- Corrigido conflito entre macro legado `min` e a camada de compatibilidade Android.
- Removido `CBTMessageBox.cpp` do build Android por ser um modulo puramente Win32 baseado em hook CBT.
- Adicionados novos shims Android para `OffsetRect`, `_vsntprintf` e `GetKeyState`.
