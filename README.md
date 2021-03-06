# Template for Cross Platform Release Builds

## Badges

<div align="center" style="width: 60%; margin: 0 auto;">

| Description |                                                                                                                                                       Badges                                                                                                                                                        |
| :---------: | :-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
|    LGTM     | [![LGTM Grade](https://img.shields.io/lgtm/grade/cpp/github/hungrybluedev/release-test)](https://lgtm.com/projects/g/hungrybluedev/release-test/context:cpp) [![LGTM Alerts](https://img.shields.io/lgtm/alerts/github/hungrybluedev/release-test)](https://lgtm.com/projects/g/hungrybluedev/release-test/alerts/) |
|   License   |                                                                                                               [![GitHub](https://img.shields.io/github/license/hungrybluedev/release-test)](LICENSE)                                                                                                                |
|    CI/CD    |                  [![CI for release tags](https://github.com/hungrybluedev/release-test/workflows/CI%20for%20release%20tags/badge.svg) ![Main CI test](https://github.com/hungrybluedev/release-test/workflows/Main%20CI%20test/badge.svg)](https://github.com/hungrybluedev/release-test/actions)                   |
|   Version   |                                                                          [![GitHub release (latest by date)](https://img.shields.io/github/v/release/hungrybluedev/release-test)](https://github.com/hungrybluedev/release-test/releases)                                                                           |

</div>

## Introduction

This project is based off my previous one: [Template for CMake based C Projects](https://github.com/hungrybluedev/CMake-Basic-C-Template)

The goal of this experiment/template is to make an accessible starting point for creating cross-platform builds for CMake-based C projects. Additionally, it uploads the binaries built and adds them to the release.

## Using This Template

### Creating A New Project

The recommended way is to download the source code and extact into the desired folder. Then change the names of the folders, the values in the config files, etc.

To obtain the source code for the latest release, go to the [Releases](https://github.com/hungrybluedev/release-test/releases) page and download the Source Code archive (ZIP or tar.gz). Alternatively, to get the latest source, you can download the ZIP from the main page of the repository. Click on **Code** | **Download ZIP**.

## Commands

To generate the build files:

```bash
/path/to/src $ cmake -G"Unix Makefiles" -S . -B build
```

This generates _Unix Makefiles_ for the src (`.`) in the build directory (`build`).

- Type `cmake --help` for a list of available generators.
- (Suggestion) Change `-B build` to `-B release` for release.
- Leave out the `-G` option to use the default generator.

To start the build:

```bash
/path/to/src $ cmake --build build
```

Note that we do not need to move into the `build` folder.

To build a release version:

```bash
/path/to/src $ cmake --build release --config Release
```

Check [this link](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html) for more information of the different configurations available.

## The `.github/workflows/release.yml` File

This is the main highlight for this repository. The `main.yml` file is the same as the one used in [Template for CMake based C Projects](https://github.com/hungrybluedev/CMake-Basic-C-Template).

A simplified explanation of the algorithm is as follows:

1. Create a Github release.
2. Use a matrix of OSes so that the same "script" can be run on all the target platforms.
3. Checkout the code from the repository.
4. Download (from the internet, or cache) and install CMake.
5. Run CMake using the `Release` configuration.
6. Upload the binary from that particular OS to the newly created release.

There is a conditional statement to account for the `.exe` extension for the Windows build. Also, the build triggers only on tags that are prefixed with `v` (for example, strings like `v2`, `v0.3`, `v1.0.23` will all match). This can be changed easily.

## Features

1. A minimal yet complete project template for cross platform CLI application builds.
2. Pragmatic directory structure is suggested with the existing code.
3. Readable CMake configuration that can be customised easily.
4. Inclusion of [µnit](https://nemequ.github.io/munit/) as the recommended unit-testing framework. It can be changed easily; just read the CMake and use the given directory structture to add your own library of choice.
5. Integration with Github Actions. It ensures cross-platform builds and ensures that all unit-tests are successful (unless skipped).
6. Inclusion of suggested badges for the project's README.
7. Creation of draft releases with multi-platform release builds available for download. (Requires some manual intervention.)

## Acknowledgement

1. Big thanks to lukka for the [get-cmake](https://github.com/marketplace/actions/get-cmake) and [run-cmake](https://github.com/marketplace/actions/run-cmake) Github actions! There was a slight issue in get-cmake which was causing the MacOS builds to fail. So I [reported it](https://github.com/lukka/get-cmake/issues/14) and Lukka responded, worked on it and it was fixed within a day!
2. Simran-B for helping me fix the single release-multiple upload issue on [Github Community](https://github.community/t/how-to-upload-release-assets-from-multiple-oses-into-one-release/136815).

## Support me

If you think my work has helped you, please consider supporting me on Ko-fi or Patreon.

[<img style="height: 36px;" height="36" src="https://raw.githubusercontent.com/hungrybluedev/hungrybluedev/master/kofi.webp">](https://ko-fi.com/hungrybluedev)
[<img style="height: 36px;" height="36"  src="https://raw.githubusercontent.com/hungrybluedev/hungrybluedev/master/patreon.webp">](https://www.patreon.com/hungrybluedev)

## Changelog

### v0.2.0

- Create only one release per tag
- Releases are all named minimally (`xtest` on \*nix systems and `xtest.exe` on Windows).
- To separate them releases, they are zipped into canonically named ZIP archives.
- Include appropriate `.gitignore` entries for Visual Studio and CLion.
- Add `.clang-format` for consistent formatting across IDEs.

### v0.1.0

- First public release
- All 3 OS build pipelines are operational.
- Instructions for building from source and using pre-built binaries are included.
