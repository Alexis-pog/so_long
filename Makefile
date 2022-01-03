NAME =  so_long

INC =

SRC1 = $(shell echo *.c)

OBJ = ${SRC1:.c=.o}

all: annoncement $(NAME) 

Cflags = -Wall -Wextra -Werror

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ) $(INC)
	@mkdir o_files
	$(CC) $(OBJ)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@mv *.o o_files
	@echo "done !!"

clean: deleting
	@rm -rf o_files
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