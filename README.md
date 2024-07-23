# CLion Qt Quick/QML Template

This repository provides a ready-to-use template for developing Qt Quick/QML applications using CLion IDE. It aims to simplify the initial setup process and provide a solid foundation for your cross-platform GUI projects.

##  Features
- Pre-configured `CMakeLists.txt` for Qt Quick projects
- Basic example of `main.cpp` to initialize and run a Qt Quick application
- Sample QML and C++ files to get you started
- Easy-to-follow structure for quick project setup

## Prerequisites
- `CLion` installed
- `Qt` installed (version 0 or later recommended)
- `CMake` installed

## Getting Started
### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/CLion-QtQuick-Template.git
cd CLion-QtQuick-Template
```

### 2. Open the Project in CLion
1. Open CLion.
2. Select "Open or Import" and navigate to the cloned repository folder.
3. Click "Open" to load the project.

### 3. Configure Qt in CLion
Ensure that CLion is configured to use your Qt installation:
1. Go to File > Settings > Build, Execution, Deployment > CMake
2. Set the CMake options to include the path to your Qt installation. For example:
   ```
   -DCMAKE_PREFIX_PATH=/path/to/Qt/6.7.2/gcc_64/lib/cmake
   ```

### 4. Build and Run
1. Click the "Build" menu and select "Build Project" to build the project.
2. Once the build is complete, click the "Run" menu and select "Run 'QtQuickApp'" to run the application.

## Project Structure
```
project_root/
│
├── CMakeLists.txt
│
├── src/
│   └── main.cpp
│
├── qml/
│   └── main.qml
│
├── include/
│
└── resources/
└── qml.qrc
```

## Contributing
Contributions are welcome! If you have suggestions for improvements or encounter any issues, feel free to open an issue or submit a pull request.
