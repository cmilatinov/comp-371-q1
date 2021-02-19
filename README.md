# Quiz 1 Submission #

### Author ###
Cristian Milatinov - 40098297

### Requirements ###

* CMake 3.17+
* VCPKG
* OpenGL
* 64-bit Libraries
    - GLFW
    - GLEW
    - GLM

### How do I get set up? ###

1. Download and Install [VCPKG](https://github.com/Microsoft/vcpkg)
2. Install the libraries from VCPKG using commandline argument "--triplet x64-windows" for 64-bit libraries on windows; "--help" to find equivalent for other OS
3. Set the CMake toolchain file for your IDE to ".../vcpkg-master/scripts/buildsystems/vcpkg.cmake"
4. Generate CMake cache
5. Build

### Controls ###

- `WASD` will move the camera relative to the direction you are looking at.
- `Left Shift` will make you move faster.
- `Space` will move you vertically up along the `y-axis`.
- `Left Control` will move you down along the `y-axis`.
- `Arrow Key Up` & `Arrow Key Down` will rotate the world around `y-axis`.
- `Arrow Key Left` & `Arrow Key Right` will rotate the world around `x-axis`.
- `Home` will reset all world and camera transformations.
- `Left Mouse Button` will make all vertical mouse movements a zoom in/out of the scene.
- `Z` will reset the zoom to its default value.
- `1 to 6` will select a letter on the screen. Default is `0`, which is the first letter from top to bottom, namely `M`.
	- `I` will scale the letter up.
	- `K` will scale the letter down.
	- `Y` will move the letter along `x`.
	- `H` will move the letter along `-x`.
	- `G` will move the letter along `z`.
	- `J` will move the letter along `-z`.
	- `F` will move the letter along `y`.
	- `V` will move the letter along `-y`.
	- `B` & `N` will rotate the letter on its `x`.
	- `Q` & `E` will rotate the letter on its `y`.
	- `,` & `.` will rotate the letter on its `z`.
- `Mouse Button 4` will make mouse movements move the camera only along its `x-axis` and `y-axis` plane.
- `Middle Mouse Button` will make all vertical mouse movements change the camera's pitch.
- `Left Mouse Button` will make all horizontal mouse movements change the camera's yaw.
- `[` will unlock the mouse cursor from the window.