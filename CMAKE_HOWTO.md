> 不管你会多少种语言, 不管说你觉得比如 "PHP是世界上最好的语言", 还是 "Java是世界上最好的语言", 都没啥用, 他们都是C些的, 如果你要用C干点事情, 掌握一个趁手的工具是非常重要的.

## Cmake的目录布局

根据CMake的代码目录布局分为两种构建方式

- In source
构建树和源码树在单个目录当中
- Out of source
构建树和源码树在不同的目录当中, 如果你有使用CMake编译某些开源项目(比如OpenCV),那么编译说明应该有这么一个过程, 创建一个`build`目录, 让后这个`build`目录下运行编译命令.

从`2.6.0`开始,CMake包含了一个Eclipse CDT 4.0及以上版本的工程生成工具. 它支持下面几种Makefile生成器. 这些生成会创建 `.project/.cproject` 工程文件, 然后可以在Eclipse中通过 `File -> Import -> Existing Eclipse Project into Workspace` 导入到Eclipse中.

**表 1**

| Generator        | Description     |
| ---------------- | --------------- |
|`Unix Makefiles`  | Unix 系统格式的 Makefile |
|`MinGW Makefiles` | |
|`MSYS Makefiles`  | |
|`NMake Makefiles` | |

Eclipse 有一个叫做 CMakeEd 的插件, 用于编辑 `CMakeLists.txt` 文件, 支持语法高亮.

![图片描述][1]

## 一个最小的CMake项目

创建`CMakeLists.txt`文件, 内容如下:

```
project(HELLO)
set(SRC_LIST main.c)
add_executable(hello ${SRC_LIST})
```

- 第一行 `project(HELLO)`, 这个命令会自动引入两个变量 `HELLO_BINARY_DIR` 和 `HELLO_SOURCE_DIR` 分别表示构建目录树和源码目录树
- `PROJECT_BINARY_DIR` 和 `PROJECT_SOURCE_DIR`, CMake自动创建的变量和上面的 `project(HELLO)` 等效.
- 变量的值可以通过 `message(${PROJECT_SOURCE_DIR})` 输出
- `set` 命令用于设置变量
- `add_exectuable` 用于告诉CMake, 生成的目标是一个可执行文件
- `add_library` 告诉CMake, 生成一个库文件
- 要打开详细的输出可以在 `CMakeLists.txt` 设置变量 `set(CMAKE_VERBOSE_MAKEFILE on)`, 或 `make VERBOSE=1`, 或 `export VERBOSE=1 && make`

> 注意:
> `CMakeList.txt` 文件中, 命令名字是不区分大小写的, 而参数和变量是区分大小写的

关于CMake定义的工程目录

- `CMAKE_SOURCE_DIR`
- `PROJECT_SOURCE_DIR`
- `<projectname>_SOURCE_DIR`

这三个变量指向的目录路径都是一样的, 对于In source编译, 指向的是顶层的工程目录, 对于 `Out of source`, 指向的就是工程编译目录, 比如`build`目录.

- `CMAKE_CURRENT_SOURCE_DIR`
- `CMAKE_CURRRENT_BINARY_DIR`
- `CMAKE_CURRENT_LIST_FILE` 当前 `CMakeLists.txt` 文件的路径
- `CMAKE_BUILD_TYPE` 控制是发(`Release`)布模式还是调试(`Debug`)模式
可通过两种方式制定, 一种是在CMakeLists.txt文件中通过设置变量制定, 另一种是在命令行制定`cmake DCMAKE_BUILD_TYPE=Release`

编译器参数

- `CMAKE_C_FLAGS`
- `CMAKE_CXX_FLAGS`

头文件路径

- `CMAKE_INCLUDE_PATH`

路径

- `CMAKE_LIBRARY_PATH` 库路径
必须配合 `FIND_LIBRARY()` 使用, 否则没有用
- `CMAKE_MODULE_PATH` 查找器路径
必须配合`FIND_PACKAGE()` 使用
- `CMAKE_INSTALL_PREFIX` 设置`make install`的安装路径, `./configure --prefix=$INSTALL_PATH`
- `BUILD_SHARED_LIBS` 默认编译的静态库, 如果要生成动态库, 可以用这个变量指定
- `UNIX`和`WIN32`, 布尔类型, 指出平台类型

### 关于查找器

当编译一个需要使用第三方库的软件时, 我们需要知道

- 头文件的位置查找路径, GCC `-I` 编译选项
- 库文件的的查找路径, GCC `-L` 编译选项
- 库的名称, GCC `-l` 编译选项

比如在我们自己的项目中, 如果需要使用到`curl`库, 可以在`CMakeLists.txt`文件中添加如下定义

```
# 头文件的位置
include_directiories(/usr/include)
# hello 需要链接 curl
target_link_libraries(hello curl)
```




### CMake命令

- 参数 `-G` 用户指定生成工程文件的类型, 也就是上面 **表-1** 中说明的4中类型.
```
# 在当前目录下生成工程文件
cmake .
#
```

## 参考资料

- [现代 CMake 指南](http://howyoung.info/2016/03/14/modern-cmake-guide)
- [CMake手册中文](https://www.zybuluo.com/khan-lau/note/254724)
- [CMake手册英文](http://www.cmake.org/cmake/help/cmake_tutorial.html)
- [在 linux 下使用 CMake 构建应用程序](https://www.ibm.com/developerworks/cn/linux/l-cn-cmake)
- [CMake入门指南](http://www.cnblogs.com/sinojelly/archive/2010/05/22/1741337.html)
- [CMake 实践](http://sewm.pku.edu.cn/src/paradise/reference/CMake%20Practice.pdf)
- [CMake 学习笔记(三)](http://blog.csdn.net/dbzhang800/article/details/6329314)

- [Autotools](http://wiki.eclipse.org/Linux_Tools_Project/Autotools/User_Guide)

  [1]: https://segmentfault.com/img/bVAqT4
