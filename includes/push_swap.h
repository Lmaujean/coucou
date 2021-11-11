/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:02:20 by lmaujean          #+#    #+#             */
/*   Updated: 2021/09/29 14:02:26 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

/**************************** STRUCTURE DE LISTE  ************************************/

typedef struct s_chunks
{
    int min;
    int max;
    int incr;
}               t_chunks;

/**************************** STRUCTURE DE LISTE  ************************************/

typedef struct  s_list
{
    int         value;
    struct s_list *next;
    struct s_list *back;
}               t_list;

/**************************** STRUCTURE DE CONTROLE  ************************************/

typedef struct  s_stack
{
    int         len;
    struct s_list *start;
    struct s_list *end;
}               t_stack;

/**************************** STRUCTURE DE PUSH_STACK  ************************************/

typedef struct  s_push
{
    t_stack *stack_a;
    t_stack *stack_b;
}               t_push;

/**************************** FONCTION DE PRINT_MOVE  ************************************/

void    ft_sa(t_push *push);
void    ft_sb(t_push *push);
void    ft_ss(t_push *push);
void    ft_ra(t_push *push);
void    ft_rb(t_push *push);
void    ft_rr(t_push *push);
void    ft_rra(t_push *push);
void    ft_rrb(t_push *push);
void    ft_rrr(t_push *push);
void    ft_pa(t_push *push);
void    ft_pb(t_push *push);

/**************************** FONCTION DE CREATION  ************************************/

t_list		*ft_new_dlist(int content);
t_stack		*ft_new_stack(int content);

/**************************** FONCTION DE RAJOUT OU SUPP DANS MA STACK  ******************/

t_stack		*ft_stack_addback(t_stack *stack, int content);
t_stack		*ft_stack_addfront(t_stack *stack, int content);
t_stack		*ft_stack_delback(t_stack *stack);
t_stack		*ft_stack_delfront(t_stack	*stack);

/**************************** FONCTION DE MOVE  ************************************/

int		ft_reverse_stack(t_stack *stack);
int		ft_rotate_stack(t_stack *stack);
int	    ft_swap_stack(t_stack *stack);
int		ft_push_stack(t_stack **dest, t_stack **src);

/**************************** FONCTION DE L'ALGO  ************************************/

int		ft_size_stack(t_stack * stack);
int		ft_stack_is_sort(t_stack *stack);
int		ft_get_index_min(t_stack *stack);
int	    ft_get_index_max(t_stack *stack);
t_push	*ft_init_stack(t_push *push);
int 	ft_sort_3(t_push *a);
void	ft_sort_5(t_push *push);
void    ft_move(t_push *push);
void	ft_sort(t_push *push);
void	print_list(t_stack *stack);
int	    ft_stack_empty(t_stack *stack);
void    ft_medium_sort(t_push *push, t_chunks *chunks);
t_chunks    *ft_init_chunks(t_chunks *chunks);
void    ft_search_move(t_stack *stack, int n, void (*top)(), void (*bot)());
int ft_get_index(t_stack *stack);

/**************************** FONCTION DE NETTOYAGE  ************************************/

t_push	*ft_clear_push(t_push *push);
void    ft_free(char **ptr);

/**************************** FONCTION DU PARSING  ************************************/

int			ft_stringisdigit(char *tab);
int			ft_strissolong(char *tab);
long long	ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void        ft_putstr_fd(char *s, int fd);
size_t      ft_strlen(const char *s);
int		    ft_isdoublon(char **ret);
int		    ft_pars(char **tab);
char	    **ft_split(char *s, char c);
char	    *ft_strdup(const char *s1);
t_stack		*ft_stock_arg_in_stack(char **argv);


#endif