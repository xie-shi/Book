# Python从入门到实践



## 第2章  变量和简单的数据类型



### 2.2 变量的命名规则

1. 变量名**只能包含字母、数字和下划线**。变量名可以以字母或下划线打头，**不可以以数字打头**
2. 变量名不能包含空格，但可以使用下划线分割其中的单词
3. 不能使用关键词作为变量名
4. 慎用变量名的大小写，且变量名既要简短，也要有辨识度。



### 2.3 字符串



1、 修改字符串的大小——通过title( ) 

```python
#title()的使用是至于字符串名的后面
name = "ada.lovelace"
print(name.title())
#则其输出为
Ada.lovelace
```



2、合并拼接字符串——直接使用 ‘ + ’ 进行拼接

```python
first_name = 'ada'
last_name = 'lovelace'
full_name = first_name + " " + last_name
print(full_name)
print(full_name.title())
#其输出为： ada lovelace
#输出2的结果：Ada lovelace
```



3、删除空白——通过rstrip( )对字符串开头与结尾处多余的空白进行删除

```python
favorite_language = ' python '
print(faverite_language)
#输出为：' python '
print(faverite_language.rstrip())
#输出为：'python'
```



4、注意单引号与双引号的使用（单引号与撇号会产生错误）



### 2.4  数字



#### 1、整数

​		在python中，可以对整数直接执行加、减、乘、除的指令



#### 2、浮点数：带小数点的数字都称为浮点数



#### 3、使用str( )避免类型错误

​		但字符串与数字进行拼接时，需要将数字通过str( )转化为字符串型，在进行拼接，如：

```python
age = 23
message = 'Happy' + str(age) +"rd Birthday!"
print(message)
#其输出为：Happy 23rd Birthday
```



## 第三章  列表



### 3.1 什么是列表

​		**列表由一系列特定顺序排列的元素组成的，在Python中，用方括号（[  ]）表示列表，用逗号分割其中的元素。**

```python
bicycle = ['trek','camondale','redline','speclialized']
print(bicycles)
>>['trek','camondale','redline','speclialized']
```



### 3.2 访问列表元素

**列表是有序集合，因此要访问列表的任何元素，只需要将该元素的位置或索引告诉Python即可**

```python
bicycle = ['trek','camondale','redline','speclialized']
print(bicycle[0])
>>trek
```

**注意：**1、索引是从0开始，而不是1。

​			2、访问列表最后一个元素，可以通过指定索引为 -1，让列表从后开始返回。



### 3.3 修改列表元素

**要修改列表元素，可以指定列表名和要修改元素的索引，再指定该元素的新值**

```python
motorcycles = ['honda','yamaha','suzuki']
print(motorcycles)
>> ['honda','yamaha','suzuki']

motorcycles[0] = 'ducati'
print(motorcycles)
>> ['honda','yamaha','suzuki']

```



### 3.4 添加列表元素



#### 1、在列表尾部添加元素——append( )

在列表中添加新元素时，最简单的方式时将元素附加到列表末尾。可以通过**append（ ）**直接添加

```python
motorcycles = ['honda','yamaha','suzuki']
print(motorcycles)
>> ['honda','yamaha','suzuki']

motorcycles.append('ducati')
print(motorcycles)
>>['honda','yamaha','suzuki','ducati']
```



#### 2、在列表中插入元素——insert( )

使用方法insert( )可在列表的任何位置添加新元素，为此需要指定新元素的索引和值。

```python
motorcycles = ['honda','yamaha','suzuki']
print(motorcycles)
>> ['honda','yamaha','suzuki']

motorcycles.insert(1,'ducati')
print(motorcycles)
>>['honda','ducati','yamaha','suzuki']
```



### 3.5 从列表中删除元素



#### 1、使用del语句删除元素

使用del可以删除任何位置处的列表元素，但需要指定要删除元素的索引。

```python
motorcycles = ['honda','yamaha','suzuki']
print(motorcycles)
>> ['honda','yamaha','suzuki']

del.motorcycles[0]
print(motorcycles)
>>['yamaha','suzuki']
```



#### 2、使用方法pop（）删除元素

有时候，要将元素从列表中删除，并继续使用它的值。

**方法pop（）可以删除列表末尾的元素，并让你能够接着使用它。**——可以将列表类比成一个栈，并将其加入到非活跃成员的列表中

```python
motorcycles = ['honda','yamaha','suzuki']
print(motorcycles)
>> ['honda','yamaha','suzuki']

popped_motorcycle = motorcycles.pop()
print(motorcycles)
print(popped_motorcycle)
>>['honda','yamaha']
>>suzuki
```



#### 3、根据值删除元素——remove（）

有时候，我们不知道列表中要删除元素所处的位置。但如果知道要删除元素的值，依然可以使用方法remove（）进行删除

```python
motorcycles = ['honda','yamaha','suzuki']
print(motorcycles)
>> ['honda','yamaha','suzuki']

motorcycles.remove('yamaha')
print('motorcycles')
>>['honda','suzuki']
```



### 3.6 、组织列表

在创建的列表中，元素的排列顺序常常时无法预测的。但我们经常需要以特定的顺序呈现信息，因此需要对列表进行一个基础的排序



#### 1、使用sort（）对列表进行永久性的排序

```python
car = ['bmw','audi','totyta','subaru']

car.sort()
print(car)
>> ['audi','bmw','subaru','toyota']#按照字母的顺序进行排序

'''
向sort( )方法传递参数reverse = Ture 
可以将列表的按照字母相反的顺序排列
'''
car.sort(reverse = Ture)
print(car)
>> ['toyota','subaru','bmw','audi']
```



#### 2、使用函数sorted（）对列表进行临时排序

具体用法与sort（）同理，但不能永久性改变列表的顺序



#### 3、倒着打印列表——reverse（）

```python
car = ['bmw','audi','totyta','subaru']
print(car)
>>['bmw','audi','totyta','subaru']

car.reverse()
print(car)
>>['subaru','totyta','audi','bmw']
```



#### 4、确定列表的长度——len（）

使用函数len( )可以快速熟悉列表的长度

```python
car = ['bmw','audi','totyta','subaru']
len(car)
>> 4
```



## 第四章：操作列表



### 1、遍历列表

经常需要遍历列表的所有元素，对每个元素执行相同的操作，因此，可以使用for循环对列表里的元素进行遍历

```python
magicians = ['alice', 'david', 'carolina'] 
for magician in magicians:      
    print(magician) 
    
>>alice
>>david
>>carolina
```

将列表magicians中每个值赋给变量magician，输出magician，直到magicians为空

**在for循环后面，没有缩进的代码都只执行一次，而不会重复执行。**

1. 忘记缩进
2. 忘记随机额外的代码行
3. 不必要的缩进
4. 遗漏了冒号



### 2、创建数值列表



#### 1、使用函数range（）

Python函数range()让你能够轻松地生成一系列的数字。

```python
for value in range(1,5):
    print(value)

>> 1
>> 2
>> 3
>> 4
```



#### 2、使用range（）创建数字列表

要创建数字列表，可使用函数list()将range()的结果直接转换为列表。如果将range()作为list()的参数，输出将为一个数字列表。

```python
numbers = list(range(1,6)) 
print(numbers) 
```

```python
[1,2,3,4,5]
```

使用函数range()时，还可指定步长。例如，下面的代码打印1~10内的偶数

```python
even_numbers = list(range(2,11,2)) 
print(even_numbers) 
```

```python
[2,4,6,8,10]
```



#### 3、对数字列表进行统计

1. min（） ——统计数字列表里最小的数值
2. max（）——统计数值列表中最大的数值
3. sum（）——数值列表中数值累加求和



#### 4、列表解析

列表解析将for循环和创建新元素的代码合并成一行，并自动附加新元素

```python
squares = [value**2 for value in range(1,11)] 
#for尾部时没有冒号的
print(squares) 
```



### 3、使用列表的一部分

何处理列表的所有元素。你还可以处理列表的部分元素——Python称之为切片。



#### 1、切片

要创建切片，可指定要使用的第一个元素和最后一个元素的索引。与函数range()一样，Python在到达你指定的第二个索引前面的元素后停止。

例如，要输出列表中的前三个元素，需要指定索引0~3，这将输出分别为0、1和2的元素：

```python
players = ['charles', 'martina', 
           'michael', 'florence', 
           'eli'] 
print(players[0:3])

>>['charles','martina','michael']
```

1. 可以生产列表的任何子集，但需要给定起始索引和终止索引

   ```python
   print(players[1:4])
   >>['martina', 'michael', 'florence']
   ```

2. 如果没有指定第一索引，Python将自动从列表开头开始

   ```python
   print(players[:4])
   >>['charles', 'martina', 'michael', 'florence']
   ```

3. 要让列表终止列表末尾出，也可以使用类似的语法

   ```python
   print(player[1:])
   >>['martina', 'michael', 'florence', 'eli']
   ```



#### 2、遍历切片

如果要遍历列表的部分元素，可在for循环中使用切片，其使用方法与遍历列表相同。



#### 3、复制列表

复制列表，可创建一个包含整个列表的切片，方法是同时省略起始索引和终止索引（[:]）。这让Python创建一个始于第一个元素，终止于最后一个元素的切片，即复制整个列表。

```python
my_foods = ['pizza', 'falafel', 'carrot cake'] 
friend_foods = my_foods[:]  

print("My favorite foods are:") 
print(my_foods)  

print("\nMy friend's favorite foods are:") print(friend_foods)  
```

```python
>>['pizza', 'falafel', 'carrot cake'] 
>>['pizza', 'falafel', 'carrot cake'] 

my_foods.append('cannoli')
friend_foods.append('ice cream')
print(my_foods)
print(friend_foods)

>>['pizza', 'falafel', 'carrot cake','cannoli']
>>['pizza', 'falafel', 'carrot cake','ice cream']
#说明两个时不同的列表元素
```

### 3、元组——**不可变的列表**

#### 1、定义元组

元组看起来犹如列表，**但使用圆括号而不是方括号来标识。**定义元组后，就可以使用索引来访问其元素，就像访问列表元素一样。 **元组里的数据时不可以修改的**

```python
dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])
```



#### 2、遍历元组

像列表一样，也可以使用for循环来遍历元组中的所有值

```python
dimensions = (200, 50)  
for dimension in dimensions:     
    print(dimension) 

>>200
>>50
```



#### 3、修改元组变量

不可以修改元组里的某个元素，但可以给存储元组的变量重新赋值，即重新定义整个元组



## 第五章 if语句



### 1、普通的条件语句

​		编程时经常需要检查一系列条件，并据此决定采取什么措施。在Python中，if语句让你能够检查程序的当前状态，并据此采取相应的措施。

```python
cars = ['audi', 'bmw', 'subaru', 'toyota']  
for car in cars:  
    if car == 'bmw':          
        print(car.upper())#upper可以令字符串全部变成大写状态     
    else:         
        print(car.title()) 
        
>>Audi
>>BMW
>>Subaru
>>Toyota
```



### 2、条件测试

#### 		1、值的比较

- **将一个变量的当前值同特定值进行比较（通过“==”进行判断真假）。**
- **两个大小写不同的值会被是为不相等，在某些与大小写无关的比较时，可以通过lower（）或者upper（）使其大小保持一致进行比较。**
- **要判断两个值是否不等，可结合使用惊叹号和等号（!=），其中的惊叹号表示不**。

#### 2、多个条件的判断

- **要检查是否两个条件都为True，可使用关键字and将两个条件测试合而为一；如果每个测试都通过了，整个表达式就为True；如果至少有一个测试没有通过，整个表达式就为False。**

- **关键字or也能够让你检查多个条件，但只要至少有一个条件满足，就能通过整个测试。仅当两个测试都没有通过时，使用or的表达式才为False。 **

  

#### 3、检查特定值是否包含在列表中



1、要判断特定的值是否已包含在列表中，可使用关键字in，例如：

```python
>>> requested_toppings = ['mushrooms', 'onions', 'pineapple']  
>>> 'mushrooms' in requested_toppings 
True  
>>> 'pepperoni' in requested_toppings 
False 
```



2、要判断特定的值未包含在列表中，可使用关键字not in，例如

```python
banned_users = ['andrew', 'carolina', 'david'] 
user = 'marie'   

if user not in banned_users:     
    print(user.title() + ", you can post a response if you wish.") 
```



#### 4、布尔表达式

它不过是条件测试的别名。与条件表达式一样，布尔表达式的结果要么为True，要么为False。  



### 3、if语句



#### 1、简单的if语句

​				**——一个测试，一个操作**

```python
if condition_test:
    do something
```

```python
age = 19
if age >= 18:
    print("You are old enough to vote!")
```



#### 2、if — else语句

if—else语句块类似于简单的if语句，但其中的else语句让你能够指定条件测试未通过时要执行的操作。

```python
age = 17  
if age >= 18:     
    print("You are old enough to vote!")     
    print("Have you registered to vote yet?") 
else:     
    print("Sorry, you are too young to vote.")
    print("Please register to vote as soon as you turn 18!")  
```



#### 3、if - elif - else结构

经常需要检查超过两个的情形，为此可使用Python提供的if-elif-else结构。Python只执行if-elif-else结构中的一个代码块，它依次检查每个条件测试，直到遇到通过了的条件测试。测试通过后，Python将执行紧跟在它后面的代码，并跳过余下的测试

**实例**

在现实世界中，很多情况下需要考虑的情形都超过两个。例如，来看一个根据年龄段收费的游乐场：

-   4岁以下免费；
-   4~18岁收费5美元； 
-  18岁（含）以上收费10美元。 

```python
age = 12  
if age < 4:
    print("Your admission cost is $0.")
elif age < 18:
    print("Your admission cost is $5.") 
else:     
    print("Your admission cost is $10.") 
```



#### 4、 使用多个elif代码块

​				**——可以根据需要使用任意数量的elif代码块。**

#### 5、省略else代码块

​			Python并不要求if-elif结构后面必须有else代码块。在有些情况下，else代码块很有用；而在其他一些情况下，使用一条elif语句来处理特定的情形更清晰：

​		else是一条包罗万象的语句，只要不满足任何if或elif中的条件测试，其中的代码就会执行，这可能会引入无效甚至恶意的数据。如果知道最终要测试的条件，应考虑使用一个elif代码块来代替else代码块。这样，你就可以肯定，仅当满足相应的条件时，你的代码才会执行。

#### 6、测试多个条件

​			if-elif-else结构功能强大，但仅适合用于只有一个条件满足的情况：遇到通过了的测试后，Python就跳过余下的测试。这种行为很好，效率很高，让你能够测试一个特定的条件。 

​		然而，有时候必须检查你关心的所有条件。在这种情况下，应使用一系列不包含elif和else代码块的简单if语句。在可能有多个条件为True，且你需要在每个条件为True时都采取相应措施时，适合使用这种方法

​		**如果你只想执行一个代码块，就使用if-elif-else结构；如果要运行多个代码块，就使用一系列独立的if语句。**

### 4、使用if语句处理列表

#### 1、检查特殊元素

```python
 request_toppings = ['mushroom','gree peppers','extra cheese']
 
 for requested_topping in requested_toppings: 
        if requested_topping == 'green peppers':         
            print("Sorry, we are out of green peppers right now.")      
        else:         
            print("Adding " + requested_topping + ".")  
            
 print("\nFinished making your pizza!") 
```

如上述代码可以看出，可以在for循环中添加一个if语句用于检查是否有相应的材料，并妥善处理相应的材料。



#### 2、确定列表不是空的

​		到目前为止，对于处理的每个列表都做了一个简单的假设，即假设它们都至少包含一个元素。我们马上就要让用户来提供存储在列表中的信息，因此不能再假设循环运行时列表不是空的。有鉴于此，在运行for循环前确定列表是否为空很重要。

```python
requested_toppings = []  

if requested_toppings:     
    for requested_topping in requested_toppings:         
        print("Adding " + requested_topping + ".")     
    print("\nFinished making your pizza!")  
else:     
    print("Are you sure you want a plain pizza?")
```

#### 3、使用多个列表

