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
		src/help_file2.c \
		src/error.c

OBJ = ${SRC1:.c=.o}

all: $(NAME) 

CFLAGS = -Wall -Wextra -Werror 


%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 
#ifeq [$(shell ls | grep "o_files" | wc -l) == 1]; then\
#	echo "done !!!";\
#fi

C_O = \
	if [ ! -e  "oubject" ]; then \
	mkdir oubject; \
	fi


$(NAME): $(OBJ) $(INC) libx
	@$(CC) $(OBJ) -g -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@$(C_O)
	@mv $(OBJ) oubject/
	@mv ./mlx/libmlx.dylib ./
	@echo "program created !!"

clean: deleting
	@rm -rf oubject
	@echo "done !!"

fclean:	deleting_lib deleting clean 
	@rm -rf $(NAME)
	@make clean -C mlx
	@rm -rf libmlx.dylib

libx:
	make -C mlx/


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