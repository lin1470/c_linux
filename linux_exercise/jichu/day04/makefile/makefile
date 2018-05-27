target=app
CPPFLAGS=./include
path=./src
src=$(wildcard ./src/*.c)
obj=$(patsubst %.c,%.o,$(src))

$(target):$(obj) #目标加依赖
	gcc $^ -o $@ # 这里是生成规则

%.o:%.c  # 如果没有依赖就走到这里
	echo $< # 先去依赖的第一个
	gcc -c $< -I $(CPPFLAGS) -o $@ # 我觉得是递进的,就是他会依次选择生成
