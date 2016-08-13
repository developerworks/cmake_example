在这个目录中防止非CMake自带的Finder, 然后在工程目录下的`CMakeLists.txt`文件中添加:

```
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
```

