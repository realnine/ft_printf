
NAME		= libftprintf.a
RM			= rm -f
AR			= ar rc

LIBFT_DIR	= ./libft
LIBFT_LIB	= libft.a

SRCS		= ./ft_printf.c\
 			  ./ft_itoa_unint.c\
			  ./ft_trans_base.c\
			  ./ft_utils.c\
			  ./ft_apply_flags.c\
			  ./ft_edit_str.c\
			  ./ft_check_flags.c\
			  ./ft_final_putstr.c\
			  ./ft_insert_0x.c\
			  ./ft_piscine.c

OBJS		= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT_DIR)/
	cp $(LIBFT_DIR)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)   

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all fclean clean re
