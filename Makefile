NAME = so_long

INC = src/so_long.h

SRC1 = src/array_maker.c \
		src/array_maker_help.c \
		src/close_funct.c \
		src/data_maker.c \
		src/help_file.c \
		src/keycode.c \
		src/keycode_help.c \
		src/main.c \
		src/map_reader.c \
		src/test.c 

OBJ = ${SRC1:.c=.o}

all: $(NAME) 

CFLAGS = -Wall -Wextra -Werror

SANITIZE = -fsanitize=address


%.o: %.c
	$(CC) -g $(CFLAGS) -Imlx -c $< -o $@ 

#ifeq [$(shell ls | grep "o_files" | wc -l) == 1]; then\
#	echo "done !!!";\
#fi

C_O = \
	if [ ! -e  "oubject" ]; then \
	mkdir oubject; \
	fi

$(NAME): $(OBJ) $(INC)
	@make -C mlx
	@$(CC) $(OBJ)  -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@$(C_O)
	@mv $(OBJ) oubject/
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