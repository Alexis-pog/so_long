NAME = so_long

#INC = 

SRC1 = $(shell echo *.c)

OBJ = ${SRC1:.c=.o}

all: $(NAME) 

Cflags = -Wall -Wextra -Werror


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

#ifeq [$(shell ls | grep "o_files" | wc -l) == 1]; then\
#	echo "done !!!";\
#fi

$(NAME): $(OBJ) $(INC)
	make -C mlx
	@$(CC) $(OBJ)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "program created !!"	

clean: deleting
	@rm -rf *.o
	@echo "done !!"
	make -C mlx clean

fclean:	deleting_lib deleting clean 
	@rm -rf $(NAME)
	

re: fclean  all
	make -C mlx re
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