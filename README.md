对于原代码的改动如下:

在impl.cc中增加了一个GetStuNo的接口

在table.cc中仿照internalGet函数新增了newInternalGet的接口

写数据库的时候忘记了去除字符串末尾的'\r',所以在调用函数的时候需要刻意加入'\r'

修改了原先的comparator

修改了table builder.cc中的 Add()函数,使其在bloom过滤器中加入k/v对中的v
