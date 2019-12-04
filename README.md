一、TinySTL项目简介
---
TinySTL是参考sgi版本的源码，同时也参考了github上几个比较优秀的开源项目。侯捷那本《STL源码剖析》你可以下载电子版的，纸质书买不买看你个人，推荐购买一本（二手即可）。

 关于项目功能测试，后期会参考google的开源项目gtest，设计一个相对简单的测试方案。项目初期我会写一点功能就写一点测试代码，同步更新在github上。

二、博客更新计划
---
更新计划我拆分成两部分，《STL从零开始-宏观概述》系列博客主要是讲述设计思想、原理和框架的，不会设计到具体代码层面的分析，但是疑难点会结合代码分析。《STL从零开始-代码实现》系列博客则主要侧重代码实现层面，会有大量代码分析，主要是把想法落地变成代码。如vector内部为何要定义 start、finish、end_of_storge，构造函数、析构函数如何利用这几个变量；alloc.h中，内存池memory_pool_start、memory_pool_end为何定义成static等细节问题。

其实我电脑里是提前存了大量博客的草稿的，我怕写的内容太抠细节了又或是重要的内容一笔带过了，所以会经常性修改。博客的书写与开发是一起进行的，我会先记录一些疑难问题，同时也慢慢构思博客框架，等开发完毕后，做一个code review，然后梳理博客内容。

本人也是很菜的，是边学习边开发的，所以整个项目可能推进会有点慢，还望大家见谅。如果你也有开发的想法可以加我QQ1282424466，一起探讨学习，如果人多的话我会考虑建一个群，互相学习进步。

三、相关资料
---
书籍资料下载：https://pan.baidu.com/s/1E9107zw3xDhHkPnmhfVTtg  提取码：wrs3
