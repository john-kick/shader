Here I test out some rendering stuff

## Building and Running on Windows

1. **Install SDL2:**

   - Download SDL2 development libraries for MinGW or MSVC from [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php).
   - Extract and copy the `include` and `lib` folders to a known location.
   - Add the SDL2 `bin` folder to your system `PATH` so `SDL2.dll` is found at runtime.

2. **Build the project:**

   - Open a terminal (e.g., Command Prompt or PowerShell).
   - Navigate to the project directory:
     ```
     cd d:\projects\shader
     ```
   - If you have `make` installed (e.g., via MSYS2 or Git Bash), run:
     ```
     make
     ```
   - Or, compile manually (replace `<SDL2_include_path>` and `<SDL2_lib_path>` with your actual paths):
     ```
     g++ -g -std=c++17 -I<SDL2_include_path> src/main.cpp -o build/shader.exe -L<SDL2_lib_path> -lSDL2main -lSDL2
     ```

3. **Run the program:**
   ```
   build\shader.exe
   ```

**Note:**  
If you see errors about missing `SDL2.dll`, copy it from the SDL2 `bin` folder to your `build` directory or add its location
