# 分布式系统

## 需要关注的问题
- 配置管理分三层：底层和操作系统层面、中间层和中间件相关的、最上层业务系统相关的
- 了解服务之间的依赖。避免某个依赖服务挂了后，软件也挂了。服务资源隔离，服务调用的数据库也要做相应的隔离
- 防范胜于治理；监控指标要上报关键指标，发生故障后能快速恢复，能快速降低影响面

## 系统分层
排查问题困难。错误案例：从接入层到负载均衡，再到服务层，再到操作系统底层，设置的 KeepAlive 的参数完全不一致，导致用户发现，软件运行的行为和文档中定义的完全不一样。
- 基础层：iaas机器、网络、存储等
- 平台层：数据库、中间件等 tomcat、redis、mysql、kafka等
- 应用层：软件服务
- 接入层：网关、CDN、DNS、LB等

## 分布式系统的核心
- 能够处理大流量，有更高的吞吐量
- 提高系统的可用性和可靠性

## 提高性能
- 缓存系统
- 负载均衡
- 异步调用
- 数据分区
- 数据镜像

## 提高稳定性
- 服务拆分
- 服务冗余
- 限流降级
- 高可用架构
- 高可用运维

## 优秀的监控系统
- 服务调用链追踪：Zipkin
- 服务调用链时长分布：可以快速定位最耗时的服务
- 服务整体的top N视图：调用量排名、请求最耗时的排名、热点排名（一个时间段的请求次数的响应时间和）
- 数据库操作关联：获取JDBC执行数据库操作的时间
- 服务资源追踪：服务所运行的容器、虚拟机、物理机的资源监控


## 服务调度
- 传统SOA希望通过ESB解决服务间的依赖。ESB（enterprise service bus企业服务总线），将所有服务连接到一个中心节点，然后ESB负责路由等服务交互
- 服务注册中心：了解服务状态和生命周期管理（类似于k8s中实例的pending、running、replicaNum、readyNum等）
- 版本管理：依赖服务之间兼容的版本号

## 解决数据副本间的一致性问题
- master-slave方案
- master-master方案
- 两阶段提交方案：
  - 阶段1: 事务发起者向所有参与者发送事务内容，询问是否可以提交事务
  - 阶段2: 如果所有参与者同意提交事务，事务发起者向所有参与者发送执行global-commit消息，收到响应后标记完成；如果存在参与者不同意，则事务发起者向所有参与者发送global-abort消息，收到响应后标记完成
- Paxos方案：系统状态的每一个更改都是一个编号的提案，系统中多数节点接受的情况下，提案才被接受


## 系统设计的过程中需要关注
- 网络不稳定
- 网络传输有延迟
- 网络带宽上下限制
- 网络不安全，会被工具
- 网络的topo是变化的
- 系统管理员可能是变化的
- 传输数据时需要花费金钱的
- 网络具有异构性

## 基本概念
- SLA service level agreement 服务等级系统

| 系统可用性%    | 宕机时间/年 | 宕机时间/月 | 宕机时间/周 | 宕机时间/天 |
| :------------- | :---------- | :---------- | :---------- | :---------- |
| 90% (1个9)     | 36.5 天     | 72 小时     | 16.8 小时   | 2.4 小时    |
| 99% (2个9)     | 3.65 天     | 7.20 小时   | 1.68 小时   | 14.4 分     |
| 99.9% (3个9)   | 8.76 小时   | 43.8 分     | 10.1 分钟   | 1.44 分     |
| 99.99% (4个9)  | 52.56 分    | 4.38 分     | 1.01 分钟   | 8.66 秒     |
| 99.999% (5个9) | 5.26 分     | 25.9 秒     | 6.05 秒     | 0.87秒     |

- NWR算法：N指的是副本数；R指的是读操作在多少个副本上成功才算是成功；W指的是写操作在多少个副本上成功才算是成功
- CAP（consistency、availability、partition tolerance）
  - CA: 一致性和可用性（两阶段提交：当存在节点不可用，则不进行变更）
  - CP: 一致性和分区容忍性（Paxos：多数节点数据一致）
  - AP：可用性和分区容忍（amazon键值数据库Dynamo：https://draveness.me/dynamo/ https://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf）

- Lamport 时钟和 Vector 时钟：vector时钟可以解决并发问题，参考https://zhuanlan.zhihu.com/p/56886156，每个进程都有一个本地的向量时间戳（记录了程序在不同进程中执行的时间戳）
- bully算法：在分布式系统中选举id最大的节点作为leader（一个节点发现当前leader挂了会主动发起选举，如果收到了比自己id更高的选举请求则放弃选择，一个节点一定时间内没有收到比自己id高的则宣布选举成功）
- FLP不可能性
-  Google File System、MapReduce、Bigtable 并称为“谷三篇”

## todoList书籍
- 分布式系统简介课程：https://github.com/aphyr/distsys-class
- Distributed systems for fun and profit电子书：https://book.mixu.net/distsys/single-page.html
- Distributed Systems: Principles and Paradigms
- Scalable Web Architecture and Distributed Systems
- Principles of Distributed Systems
- Designing Data Intensive Applications（https://www.antonfagerberg.com/files/intensive.pdf）

## Paxos todoList论文
- Bigtable: A Distributed Storage System for Structured Data
- The Chubby lock service for loosely-coupled distributed systems
- The Google File System
- MapReduce: Simplifed Data Processing on Large Clusters
- Paxos Made Live – An Engineering Perspective
- http://harry.me/blog/2014/12/27/neat-algorithms-paxos/
- https://www.semanticscholar.org/paper/Zab%3A-High-performance-broadcast-for-primary-backup-Junqueira-Reed/b02c6b00bd5dbdbd951fddb00b906c82fa80f0b3?p2df


## Raft todoList论文
- raft中文：https://www.infoq.cn/article/raft-paper/ 英文：https://raft.github.io/raft.pdf
- 动画：https://thesecretlivesofdata.com/raft/

## gossip
- 动画：https://rrmoelker.github.io/gossip-visualization/


## 分布式数据库
- Amazon Aurora: Design Considerations for High Throughput Cloud –Native Relation Databases
- Spanner: Google’s Globally-Distributed Database
- CockroachDB: https://github.com/cockroachdb/cockroach
- TiDB: https://github.com/pingcap/tidb