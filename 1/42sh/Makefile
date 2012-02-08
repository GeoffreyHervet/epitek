##
## Makefile for  in /home/yau_t//local/Projets/semestre_2/42sh
##
## Made by tom-brent yau
## Login   <yau_t@epitech.net>
##
## Started on  Fri Apr  1 14:26:44 2011 tom-brent yau
## Last update Sun May 22 22:26:34 2011 quentin rufin
##

NAME		=	42sh

LDINC		+=	-I includes

CFLAGS		=	-Wall -Wextra -pedantic -ansi -D_GNU_SOURCE $(LDINC)

LDFLAGS		=	-ltermcap

RM		=	rm -f
FIND		=	find


SRCDIR		=	src
LEXDIR		=	lexer
PARSDIR		=	parser
EXECDIR		=	exec
BUILTDIR	=	builtins
CORRECDIR	=	syntax_corrector
HISTDIR		=	history
TERMCPDIR	=	term-caps
UTILDIR		=	utils
XDIR		=	xfunc

SRC		=	main.c			\
			gnl.c			\
			my_handler.c		\
			show_prompt.c		\
			read_file.c


LEXER		=	creat_lexer.c		\
			check_function.c	\
			get_word.c		\
			quotes.c		\
			get_all_ope.c		\
			get_inibitor.c		\
			get_the_last.c		\
			choose_type.c		\
			insert_alias.c		\
			chg_tilde_to_home.c	\
			set_backslahes.c	\
			free_lex.c

PARSER		=	parser.c		\
			many_commands.c		\
			command.c		\
			init_node.c		\
			pipeline.c		\
			redirection.c		\
			simple_cmd.c		\
			simple_cmd_elem.c	\
			word_list.c		\
			read_semicolon.c


EXEC		=	exec_tree.c			\
			exec_and_or.c			\
			exec_pipe.c			\
			pipe_list_func.c		\
			exec_redir.c			\
			exec_right_red_pipe.c		\
			exec_left_red_pipe.c		\
			exec_double_red_left.c		\
			put_in_buff.c			\
			exec_cmd.c			\
			check_cmd.c			\
			exec_no_fork.c			\
			wait_and_ret.c			\
			redir_cmd.c			\
			wait_all.c			\
			show_message.c


BUILTINS	=	alias.c			\
			cd_cmd.c		\
			chg_pwd.c		\
			echo_cmd.c		\
			env_cmd.c		\
			exit_cmd.c		\
			if_builtin.c		\
			setenv_cmd.c		\
			unalias.c		\
			unsetenv_cmd.c		\
			echo_numbers.c


UTILS		=	cpy_env.c		\
			find_env_var.c		\
			free_env.c		\
			free_node_ret_leaf.c	\
			free_tree.c		\
			get_tab_arg.c		\
			print.c			\
			strclen.c		\
			creat_env.c		\
			len_eq_c.c		\
			find_path.c		\
			my_getnbr.c		\
			epur_str.c


HISTORY		=	creat_history.c		\
			add_elem_to_history.c	\
			display_history.c	\
			update_history.c	\
			look_in_history.c	\
			history_modifiers.c	\
			replace_cmd.c		\
			free_hist.c


TERMCP		=	read_key.c		\
			back_key.c		\
			del_key.c		\
			gere_cut.c		\
			gere_window.c		\
			go_to_idx.c		\
			init_termcp.c		\
			is_printable.c		\
			mode_terminal.c		\
			move_cursor_end.c	\
			move_cursor_home.c	\
			move_cursor_left.c	\
			move_cursor_right.c	\
			pars_keys.c		\
			refresh.c		\
			remove_key_from_str.c	\
			replace_with_spaces.c	\
			update_result.c		\
			up_history.c		\
			down_history.c		\
			tab_key.c		\
			gere_ctrl_t.c		\
			gere_ctrl_l.c		\
			gere_ctrl_k_y.c		\
			gere_ctrl_w.c		\
			gere_ctrl_u.c		\
			look_in_dir.c		\
			look_in_exec.c		\
			get_max_len.c		\
			complete_file.c		\
			aff_list.c		\
			get_win_col.c


CORRECTION	=	calc_min_of_three_values.c	\
			calc_dist_levenshtein.c		\
			syntax_correction.c		\
			free_ll_syntax_correction.c	\
			xcalc_dist_levenshtein.c	\
			get_ll_syntax_correction.c	\
			order_ll_syntax_correction.c	\
			apply_correction.c


XFUNC		=	xchdir.c		\
			xmalloc.c		\
			xclose.c		\
			xdup2.c			\
			xwait.c			\
			xstrdup.c		\
			xpipe.c			\
			xfork.c			\
			xopen.c			\
			xopen_mod.c		\
			xexecve.c		\
			xwaitpid.c		\
			xkill.c			\
			xsignal.c		\
			xtputs.c		\
			xtgetstr.c		\
			xwrite.c


SRC		+=	$(addprefix $(LEXDIR)/,$(LEXER))
SRC		+=	$(addprefix $(PARSDIR)/,$(PARSER))
SRC		+=	$(addprefix $(EXECDIR)/,$(EXEC))
SRC		+=	$(addprefix $(BUILTDIR)/,$(BUILTINS))
SRC		+=	$(addprefix $(CORRECDIR)/,$(CORRECTION))
SRC		+=	$(addprefix $(HISTDIR)/,$(HISTORY))
SRC		+=	$(addprefix $(TERMCPDIR)/,$(TERMCP))
SRC		+=	$(addprefix $(UTILDIR)/,$(UTILS))
SRC		+=	$(addprefix $(XDIR)/,$(XFUNC))

OBJSS		=	$(SRCS:.c=.o)
SRCS		=	$(addprefix $(SRCDIR)/,$(SRC))

OBJ_DIR		=	objs
OBJS		=	$(addprefix $(OBJ_DIR)/,$(OBJSS))
OBJ		=	$(SRCS:.c=.o)

PERCENT		=	.percent/percent.out

ifeq ($(verbose),1)
  AFF		=\n
else
  AFF		=\r
endif

ASCII_ART	= @cat .make_msg 2>/dev/null

$(NAME):	$(OBJ_DIR) $(OBJS)
		@printf "$(AFF)\033[00mCompilation with flags : \033[33m$(CFLAGS)\033[33m\n"
		@printf "\033[00mLinkage with flags : \033[33m$(LDFLAGS)\033[34m\n"
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
		@printf "\033[00m"
		$(ASCII_ART)

all:		$(PERCENT) $(NAME)


$(PERCENT):
		@$(CC) -o $(PERCENT) .percent/percent.c

$(OBJ_DIR)/%.o:	%.c
		@printf "\033[00m[%02d%%][\033[36m$<\033[00m]%50s\033[031m$(AFF)" `$(PERCENT) $@ $(OBJS) 2>/dev/null`
		@$(CC) -o $@ -c $< $(CFLAGS)
 
$(OBJ_DIR):
		@mkdir `find ./src/ -type d | sed "s#$(SRCDIR)#$@/$(SRCDIR)#g"` -p

clean:
		@$(FIND) . \( -name '*~' -or -name '#*#' \) -exec rm {} \;
		@$(RM) $(OBJS)
		@echo "Object directory cleaning !"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(NAME) deleted !"

re:		fclean all

norme:
		@echo "##### - Moulinorme is comming O_o - #####"
		@/afs/epitech.net/users/prof/astek/public/norme -nocheat `find .`


.PHONY:		all clean fclean re norme ASCII_ART
