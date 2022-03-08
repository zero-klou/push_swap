/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaustin <vaustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:50 by vaustin           #+#    #+#             */
/*   Updated: 2022/02/02 15:42:07 by vaustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft_src/libft.h"

typedef struct s_elem
{
	int				value;
	int				order;
	int				flag;
	struct s_elem	*next;
}	t_elem;

typedef struct s_struct
{
	t_elem		*next;
	t_elem		*mid;
	t_elem		*max;
	int			flag;
	size_t		size;
	t_elem		*list_a;
	t_elem		*list_b;
}	t_struct;

void		sort_three(t_struct *data, int f);
int			len_push(t_struct *data, t_elem *lst);
int			len_push_a(t_struct *data, t_elem *lst);
void		sort_five_a(t_struct *data);
void		sort_five_b(t_struct *data);
void		sort_many(t_struct *data);
void		push_from_a(t_struct *data);
void		push_from_a_2(t_struct *data);
void		sort_b(t_struct *data);
int			check_top_a(t_struct *data);
int			*parse_numbers_one(char **argv, t_struct *data);
int			*parse_numbers_many(int argc, char **argv, t_struct *data);
long long	ft_atoi_mod(const char *str);
void		pointer_err(t_struct *data);
int			is_sorted(int *numbers, t_struct *data);
int			is_duples(int *numbers, t_struct *data);
void		ft_lstadd_back_mod(t_elem **lst, t_elem *new);
t_elem		*ft_lstnew_mod(int content);
t_elem		*ft_lstlast_mod(t_elem *lst);
t_elem		*ft_lst_prelast_mod(t_elem *lst);
void		ft_lstclear_mod(t_elem **lst);
void		ft_lstiter_order(int *numbers, t_struct *data);
int			ft_lstsize_mod(t_elem *lst);
void		ft_lstadd_front_mod(t_elem **lst, t_elem *new);
void		ft_quick_sort(int *numbers, t_struct *data);
void		init_stack_a(int *numbers, t_struct *data);
void		sa(t_struct *data);
void		sb(t_struct *data);
void		ss(t_struct *data);
void		pb(t_struct *data);
void		pa(t_struct *data);
void		ra(t_struct *data);
void		rb(t_struct *data);
void		rr(t_struct *data);
void		rra(t_struct *data, int f);
void		rrb(t_struct *data, int f);
void		rrr(t_struct *data);
t_elem		*get_max(t_struct *data);
t_elem		*get_max_b(t_struct *data);
t_elem		*get_mid(t_struct *data, int flag);
void		lets_sort_already(t_struct *data);
int			is_stack_sorted(t_elem *lst);
void		rotate_back_a_b(t_struct *data, int back);
t_elem		*get_elem_by_order(t_struct *data, int order);
void		ft_swap(int *a, int *b);

#endif