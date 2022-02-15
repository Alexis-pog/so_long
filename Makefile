NAME = so_long

INC = src/so_long.h

SRC1 = $(shell echo src/*.c) 

OBJ = ${SRC1:.c=.o}

all: $(NAME) 

Cflags = -Wall -Wextra -Werror

SANITIZE = -fsanitize=address

%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -Imlx -c $< -o $@

#ifeq [$(shell ls | grep "o_files" | wc -l) == 1]; then\
#	echo "done !!!";\
#fi

c_o = \
	if [ ! -e  "oubject" ]; then \
	mkdir oubject; \
	fi

$(NAME): $(OBJ) $(INC)
	@make -C mlx
	@$(CC) $(OBJ)  -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@$(c_o)
	@mv src/*.o oubject/
	@echo "program created !!"

clean: deleting
	@rm -rf oubject
	@echo "done !!"

fclean:	deleting_lib deleting clean 
	@rm -rf $(NAME)
	

re: fclean  all
	
annoncement :
		@echo "creating program..."

deleting :
	@echo "deleting OBJECT_FILES files..."

deleting_lib :
	@echo "deleting program...."

save: fclean 
	@git add *.c *.h Makefile
	@git commit -m autosave
	@git push