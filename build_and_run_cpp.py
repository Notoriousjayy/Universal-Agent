import subprocess
import platform

def build_and_execute_cpp_code(source_file):
    # Determine the platform
    current_platform = platform.system()

    # Compile the C++ code based on the platform
    try:
        if current_platform == 'Windows':
            subprocess.run(['g++', source_file, '-o', 'output.exe'], check=True)
        else:
            subprocess.run(['g++', source_file, '-o', 'output'], check=True)
        print('Build successful.')
    except subprocess.CalledProcessError as e:
        print('Build failed.')
        print(e)
        return
    
    # Run the compiled executable based on the platform
    try:
        if current_platform == 'Windows':
            subprocess.run(['output.exe'], check=True)
        else:
            subprocess.run(['./output'], check=True)
    except subprocess.CalledProcessError as e:
        print('Execution failed.')
        print(e)

if __name__ == "__main__":
    # Specify the C++ source file to build and execute
    cpp_source_file = 'your_cpp_file.cpp'
    build_and_execute_cpp_code(cpp_source_file)
