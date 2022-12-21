NAME  =  cub3d
BNAME  =  cub3d_bonus

CC = cc

FLAGS = -Wall -Werror -Wextra

PATH_OBJ = obj/

CSRC = parssing/check_data.c\
		parssing/check_elements.c\
		parssing/check_map_content.c\
		parssing/check_map_format.c\
		parssing/check_map_wall.c\
		parssing/data_init.c\
		parssing/exit.c\
		parssing/get_data.c\
		parssing/read_file.c\
		parssing/utils/ft_split.c\
		parssing/utils/utils_two.c\
		parssing/utils/utils.c\
		\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		\
		utils/normalizeangle.c\
		utils/to_rad.c\
		utils/ft_distance.c\
		utils/my_mlx_pixel_put.c\
		utils/render_line.c\
		utils/render_rect.c\
		utils/hundel_keys.c\
		utils/thereiswall.c\

SRC = 	mandatory/draw_textures.c\
		mandatory/horizontal_inter.c\
		mandatory/intersections.c\
		mandatory/main.c\
		mandatory/rays.c\
		mandatory/render_win.c\
		mandatory/vertical_inter.c\

BSRC =	bonus/draw_textures.c\
		bonus/drawmap.c\
		bonus/horizontal_inter.c\
		bonus/intersections.c\
		bonus/main.c\
		bonus/mouse.c\
		bonus/rays.c\
		bonus/render_win.c\
		bonus/vertical_inter.c\

COBJ = $(addprefix $(PATH_OBJ), $(CSRC:.c=.o))
OBJ = $(addprefix $(PATH_OBJ), $(SRC:.c=.o))
BOBJ = $(addprefix $(PATH_OBJ), $(BSRC:.c=.o))

all : $(NAME)
bonus: $(BNAME)

$(NAME): $(OBJ) $(COBJ)
	$(CC) $(FLAGS) $(OBJ) $(COBJ) -framework OpenGL -framework AppKit -lmlx -o $(NAME)

$(BNAME): $(BOBJ) $(COBJ)
	$(CC) $(FLAGS) $(BOBJ) $(COBJ) -framework OpenGL -framework AppKit -lmlx -o $(BNAME)

$(COBJ): $(PATH_OBJ)%.o: %.c parssing/parss.h utils/tools.h get_next_line/get_next_line.h
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c  $< -o $@

$(OBJ): $(PATH_OBJ)%.o: %.c mandatory/cub3d.h
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c  $< -o $@

$(BOBJ): $(PATH_OBJ)%.o: %.c bonus/cub3d_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c  $< -o $@

clean :
	@rm -rf $(PATH_OBJ)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(BNAME)

re : fclean all

.PHONY: all clean fclean re bonus
