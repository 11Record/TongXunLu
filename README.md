# TongXunLu
# 📇 通讯录管理系统 (Address Book Management System)

基于C++编写的通讯录管理系统，提供了完整的联系人管理功能，支持添加、显示、删除、查找、修改和清空联系人等操作。

## ✨ 功能特性

- **联系人管理**：
  - ✅ 添加新联系人（姓名、性别、年龄、电话、住址）
  - ✅ 显示所有联系人信息
  - ✅ 按姓名查找联系人
  - ✅ 删除指定联系人
  - ✅ 修改联系人详细信息
  - ✅ 清空所有联系人
  
- **用户友好界面**：
  - 🖥️ 清晰的菜单导航系统
  - 🔄 操作结果即时反馈
  - 🛡️ 输入验证与错误处理
  
- **数据结构**：
  - 🧩 使用结构体存储联系人信息
  - 🔢 固定大小数组管理联系人数据（最大1000条）
  - ⚡ 高效的查找和删除算法

## 🛠️ 技术实现

### 核心数据结构

```cpp
#define MAX 1000  // 最大联系人数量

// 联系人结构体
struct Person {
    string m_Name;    // 姓名
    string m_Sex;     // 性别（"1"=男，"2"=女）
    int m_Age;        // 年龄
    string m_Phone;   // 手机号
    string m_Addr;    // 住址
};

// 通讯录结构体
struct Addressbooks {
    Person personArray[MAX]; // 联系人数组
    int m_Size = 0;          // 当前联系人数量
};
```
### 主要功能模块
```cpp
// 功能函数声明
void showMenu();                  // 显示主菜单
void addPerson(Addressbooks*);    // 添加联系人
void showPerson(Addressbooks*);   // 显示联系人
void deletePerson(Addressbooks*); // 删除联系人
void findPerson(Addressbooks*);   // 查找联系人
void updatePerson(Addressbooks*); // 修改联系人
void cleanPerson(Addressbooks*);  // 清空联系人
```
## 🚀 如何运行
### 编译说明
1、确保已安装C++编译器（推荐使用g++或MSVC）

2、克隆仓库：

```bash
git clone https://github.com/11Record/TongXunLu.git
```
3、进入项目目录：
```bash
cd TongXunLu
```
4、编译程序：
```bash
g++ main.cpp -o addressbook
```
5、运行程序：
```bash
# Windows
addressbook.exe

# Linux/Mac
./addressbook
```
### 使用说明
1、程序启动后显示主菜单：
```text
***************************
*****  1、添加联系人   *****
*****  2、显示联系人   *****
*****  3、删除联系人   *****
*****  4、查找联系人   *****
*****  5、修改联系人   *****
*****  6、清空联系人   *****
*****  7、退出通讯录   *****
***************************
```
2、根据提示输入数字选择操作

3、按照提示输入联系人信息

4、支持同名联系人管理和批量操作

##  📂 项目结构
```text
TongXunLu/
├── main.cpp           # 程序主文件
├── README.md          # 项目说明文档
└── .gitignore         # Git忽略文件配置
```
## 🔍 功能演示
### 添加联系人
```text
请输入姓名：张三
请输入性别（1男 2女）：1
请输入年龄：28
请输入手机号：13800138000
请输入住址：北京市海淀区
添加成功！
```
### 显示联系人
```plaintext
姓名：张三    性别：男    年龄：28    电话号：13800138000    住址：北京市海淀区
姓名：李四    性别：女    年龄：32    电话号：13900139000    住址：上海市浦东新区
```
### 查找联系人
```text
请输入您要查找的联系人: 张三
*****
姓名：张三    性别：男    年龄：28    电话号：13800138000    住址：北京市海淀区
查找成功,一共有1条记录
```
## 🤝 贡献指南
#### 欢迎提交Pull Request改进项目：

1、**Fork**项目仓库

2、创建特性分支：

```bash
git checkout -b feature/your-feature
```
3、提交更改：

```bash
git commit -am 'Add some feature'
```
4、推送到分支：

```bash
git push origin feature/your-feature
```
5、创建**Pull Request**

## 📅 未来计划
- 实现数据持久化（文件存储）

- 添加联系人分组功能

- 支持按多种条件排序

- 开发图形用户界面(GUI)

## 📜 许可证
本项目采用 [MIT License](https://github.com/github-linguist/linguist?tab=MIT-1-ov-file#)，欢迎自由使用和修改。

---

>项目地址：[https://github.com/11Record/TongXunLu](https://github.com/11Record/TongXunLu)
