NAME  =  cub3d

CC = cc

FLAGS = -Wall -Werror -Wextra -g

PATH_SRC0 = parssing/

PATH_SRC1 = get_next_line/

PATH_SRC2 = utils/

PATH_SRC3 = ./

PATH_OBJ = obj/

FILES_SRC0 =  check_data.c\
			  check_elements.c\
			  check_map_content.c\
			  check_map_format.c\
			  check_map_wall.c\
			  data_init.c\
			  exit.c\
			  get_data.c\
			  read_file.c

FILES_SRC1 = get_next_line.c\
			  get_next_line_utils.c

FILES_SRC2 = ft_split.c\
			  utils_two.c\
			  utils.c\
			  normalizeangle.c\
			  ft_distance.c\
			  to_rad.c\
			  render_line.c\
			  my_mlx_pixel_put.c\
			  hundel_keys.c\
			  render_rect.c\

FILES_SRC3 = render_map.c rays.c intersections.c

OBJ = $(addprefix $(PATH_OBJ), $(FILES_SRC0:.c=.o))\
	  $(addprefix $(PATH_OBJ), $(FILES_SRC1:.c=.o))\
	  $(addprefix $(PATH_OBJ), $(FILES_SRC2:.c=.o))\
	  $(addprefix $(PATH_OBJ), $(FILES_SRC3:.c=.o))\

SRC = $(addprefix $(PATH_SRC0), $(FILES_SRC0:.c=.o))\
	  $(addprefix $(PATH_SRC1), $(FILES_SRC1:.c=.o))\
	  $(addprefix $(PATH_SRC2), $(FILES_SRC2:.c=.o))\
	  $(addprefix $(PATH_SRC3), $(FILES_SRC3:.c=.o))\

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) main.c $(OBJ) -framework OpenGL -framework AppKit -lmlx  -o $(NAME)

$(PATH_OBJ)%.o: $(PATH_SRC2)%.c cub3d.h main.c
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(FLAGS) -c  $< -o $@

$(PATH_OBJ)%.o: $(PATH_SRC1)%.c
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@

$(PATH_OBJ)%.o: $(PATH_SRC0)%.c
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@

$(PATH_OBJ)%.o: $(PATH_SRC3)%.c
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(PATH_OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
