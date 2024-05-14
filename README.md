# RingQ

### 背景：

后渗透场景，杀毒软件落地秒了我的大保健 fscan mimikatz ...  这还让我怎么内网渗透啊？





### 目的：

不用关心怎么实现免杀，也不用浪费时间和精力去对某一款工具进行专项修改达成免杀效果

助力每一位像我这样的脚本小子快速实现免杀，hvv尽快打穿点目标内网

支持bypass 360 火绒 Windows Defender，一键免杀上线CS、fscan、mimikatz ...




### 使用方法：

1. 你的任意exe工具，放在与Create.exe 同文件夹下运行即可，会生成一个混淆的main.txt文件。
   
   Create.exe 此程序仅用于生成main.txt文件，可能存在报毒(c++你懂的 helloworld都报毒) 添加白名单or虚拟机断网使用都可以。

   ```
   Create.exe mimikatz.exe
   ```
![](https://github.com/T4y1oR/RingQ/blob/main/image-20240511163723965.png)

2. 将main.txt和RingQ.exe上传到目标机器，执行 RingQ.exe ~

   内置反沙箱等等等机制 执行后有些许延迟 耐心一会儿~

   ```
   RingQ.exe
   ```
![](https://github.com/T4y1oR/RingQ/blob/main/image-20240511163838236.png)
![](https://github.com/T4y1oR/RingQ/blob/main/image-20240511172315793.png)

### **微步**
![](https://github.com/T4y1oR/RingQ/blob/main/image-20240511162750465.png)
### **企业360**（2024.05.14更新）
![](https://github.com/T4y1oR/RingQ/blob/main/image-20240511162705202.png)
![](https://github.com/T4y1oR/RingQ/blob/main/image-20240511165253870.png)
### **Windows Defender**（2024.05.14更新）
![](https://github.com/T4y1oR/RingQ/blob/main/image-20240511162705256.png)
### **火绒（2024.05.14更新）**
![](https://github.com/T4y1oR/RingQ/blob/main/image-20240511162712449.png)



## 承诺无任何后门，后续如报毒属于正正正正正常现象，提issues耐心等待更新即可。tips:  Star后更新更快！

## 项目仅供进行学习研究，切勿用于任何非法未授权的活动，如个人使用违反安全相关法律，后果与本人无关。



### 更新日志
2024.05.14 360QVM202报毒 已更新，这个报毒自行更换图标，添加签名...  ~~如果持续出现这个问题，考虑要不要出个专项QVM202脚本~~ 
           Releases新增RingQ.exe原编译出的main.exe文件，方便大家自定义修改降熵

2024.05.11 项目发布，微步纯绿 企业360云沙箱 火绒   ~~没传VT是为了能大家能用久点，大家随意~~



### TODO

- [ ] 不让我传fscan 我直接干掉AV？
- [ ] 强化版unhook
- [ ] ...

