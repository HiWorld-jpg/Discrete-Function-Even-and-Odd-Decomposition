# Discrete-Function-Even-and-Odd-Decomposition
C语言+EasyX库，实现可视化、可交互的离散函数奇偶分解


1.项目初衷：
在学习奥本海姆著的《信号与系统》第一章关于函数奇偶分解内容的时候，我想用C语言+EasyX库可视化地实现一下，也没什么用，就当是娱乐一下。

2.项目理论原理：
原理在书中有明确的表述。用公式表述应该如下：
对于任意函数x(t)，则其分解出的奇函数Oddx(t)=(x(t)-x(-t))/2，偶函数Evenx(t)=(x(t)+x(-t))/2。

3.项目实现细节：

#1 怎么实现函数？
=>无法实现连续函数，那么就实现离散函数。函数定义域设置为-10到10，且只能取整数。函数值用一维数组储存，坐标（2，4）对应x(12)=4.

#2 怎么实现用户可交互地输入函数？
=>画出单元格，实时检测鼠标的位置，找到离鼠标最近的那个单元格，此时按Ctrl键就可以将值输入数组。

#3 怎么实现可视化界面？
=>我定义了两个类，一个是Button类，一个是Text_for_float类。这两个类很好用，在我其他一些项目里也经常使用，改写参数就行，不需要重写，非常方便。
