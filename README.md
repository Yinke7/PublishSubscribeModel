# 发布订阅模式

## C语言实现

### 订阅者

* 添加订阅事件

```c
/**
 * @brief 添加订阅事件及其回调函数到数据中心
 * @param event: 订阅的事件
 * @param func: 对应的回调函数
 */
void AddSubscriberEvent(char *event, HandleEvent func);
```

* 删除订阅事件

```c
/**
 * @brief 从数据中心删除订阅事件
 * @param event: 取消订阅的事件
 * @param func: 对应的回调函数
 */
void DeleteSubscriberEvent(char *event, HandleEvent func);
```

### 发布者

* 发送发布信息

```c
/**
 * @brief 发布事件及其数据到数据中心
 * @param event: 发布的事件
 * @param data: 对应的数据
 */
void SendPublishEvent(char *event, void *data);
```

* 清除发布信息

```c
/**
 * @brief 从数据中心清除发布的事件及其数据
 * @param event: 清除发布的事件
 * @param data: 对应的数据
 */
void ClearPublishEvent(char *event, void *data);
```

### 事件处理中心

* 事件处理

```c
/**
 * @brief 数据中心处理发布信息和订阅事件
 */
void ProcDataCenter(void);
```

## C++ 实现

## 参考链接

* [C/C++实现发布订阅模式](https://zhuanlan.zhihu.com/p/484171260 )
