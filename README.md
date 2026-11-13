# Lichii Dusk Updated

A community-maintained emulator build focused on **The Duskbloods**.

This project continues the older **Lichii-Dusk** fork, updating its codebase to **Lichii 160** because the original Lichii-Dusk build was no longer being updated. It also includes additional fixes and improvements aimed at running The Duskbloods.

This is an independent community project. It is not an official release of Lichii and is not affiliated with Nintendo or FromSoftware.

## Downloads

Get the latest builds from the [Releases](https://github.com/mrsam035/lichii-dusk-updated/releases) page.

Choose the package that matches your platform and build type. Windows x86_64 packages are available in standard and PGO variants.

The emulator does not include the game, console keys, or firmware. Use only game files and system files that you are legally entitled to use.

## The Duskbloods Network Test

This fork preserves the Duskbloods-specific integration from the original Lichii-Dusk project, including support for the community [playDB-CNT launcher](https://github.com/sikoGD/playDB-CNT).

### Requirements

- A legally obtained copy of **The Duskbloods Network Test**.
- The Switch 2 system files and decryption keys required by the emulator.
- Windows 10/11 x64 to use the supplied playDB-CNT launcher.
- The [playDB-CNT launcher](https://github.com/sikoGD/playDB-CNT), configured using its own instructions.

### Launching

1. Extract the emulator build to a short, writable folder, for example `C:\\Games\\Lichii-Duskbloods\\`.
2. Install your own keys and firmware through the emulator's **Tools** menu.
3. In playDB-CNT's `launcher_settings.json`, set `emulator` to this build's `lichii.exe` and `game` to your Network Test game folder. For example:

   ```json
   {
     "emulator": "C:\\Games\\Lichii-Duskbloods\\lichii.exe",
     "game": "C:\\Games\\THE DUSKBLOODS NETWORK TEST"
   }
   ```

4. Start `Play.Duskbloods.exe` and launch the game through the launcher. The launcher supplies the local network-test configuration; launching the Network Test directly from `lichii.exe` will not provide that configuration.

## Included Duskbloods-focused changes

- playDB-CNT integration, including launcher-driven host redirection, loopback-only networking controls, and trust for the launcher's local test certificate.
- Duskbloods-specific BCAT handling.
- Native shader translation and stack-related shader fixes.
- Vulkan fixes for layered fog-volume clears and the neural-upscaler scratch-buffer clear.
- Faster GPU-memory subrange lookup and additional performance controls.
- Further updates and fixes inherited from the Lichii 160 codebase.

Some fixes from the original fork have since been implemented or superseded upstream. This project keeps the newer implementation where appropriate instead of blindly reapplying older patches.

## Compatibility and troubleshooting

Compatibility, performance, and rendering may vary depending on the game build, system files, hardware, graphics driver, and emulator settings. Visual issues, stuttering, or crashes may still occur; no specific performance level is guaranteed.

When reporting a problem, include:
- The exact release/build and game version.
- Your CPU, GPU, and graphics driver version.
- The settings used and clear steps to reproduce the issue.
- A screenshot and the relevant emulator log, after checking the log for personal information.

Do not upload game files, keys, firmware, or private account information.

## Building

Build instructions and inherited development documentation are available in the [docs](docs) directory. Some internal build target names and legacy documentation may still use names inherited from upstream projects.

## Credits and license

This project builds on the work of the Lichii, Eglantine, Eden, yuzu, and Sudachi projects and their contributors. Original copyright notices and third-party licenses are retained.

See [LICENSE.txt](LICENSE.txt) and the source files for applicable license terms.
