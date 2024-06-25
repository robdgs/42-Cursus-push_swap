/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:28:43 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/24 18:57:26 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	long			dish;
	int				eff_a;
	int				eff_b;
	int				target;
	int				index;
	int				posiz;
	struct s_stack	*next;
}	t_stack;

typedef struct s_fill
{
	t_stack		*stack_a;
	long int	nb;
	int			len;
	int			i;
	char		**splitted;
}	t_fill;

//mosse:
void		ft_sa(t_stack **stack_a);
void		ft_sb(t_stack **stack_b);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_b, t_stack **stack_a);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack_a);
void		ft_rb(t_stack **stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rra(t_stack **stack_a);
void		ft_rrb(t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);

//list funcs
int			ft_stack_len(t_stack *stack);
void		ft_add_back(t_stack **stack, t_stack *new);
t_stack		*ft_stack_last(t_stack *stack);
t_stack		*ft_stack_penultimate(t_stack *stack);
t_stack		*ft_new_stack(int value);
t_stack		*ft_highest_val(t_stack *stack);
void		ft_set_index(t_stack *stack_a, int stack_len);
t_stack		*ft_fill_multiple_av(int ac, char *av[]);
t_stack		*ft_fill_two_av(char *av[]);

//exec mosse & computaz effic calc
void		ft_is_efficient(t_stack **stack_a, t_stack **stack_b);
void		ft_exec_most_eff(t_stack **stack_a, t_stack **stack_b);
void		ft_exec_move(t_stack **a, t_stack **b, int eff_a, int eff_b);

//exec interne specifiche
void		ft_exec_rrr(t_stack **a, t_stack **b, int *eff_a, int *eff_b);
void		ft_exec_rr(t_stack **a, t_stack **b, int *eff_a, int *eff_b);
void		ft_exec_rotation_a(t_stack **a, int *eff);
void		ft_exec_rotation_b(t_stack **b, int *eff);

//checks
int			ft_is_sorted(t_stack *stack);
int			ft_isdigit(char c);
int			ft_plusminus(char c);
int			ft_is_accept_for_atoi(char *str);
int			ft_sign_match(char *s1, char *s2);
int			ft_strict_atoi(char *str);
int			ft_checkdup(t_stack *a);

//sorting
void		ft_easy_sort(t_stack **stack_a);
void		ft_terror_sort(t_stack **stack_a, t_stack **stack_b);

//algo utils
int			ft_absol(int n);
void		ft_free(t_stack **stack);
void		ft_error(t_stack **stack_a, t_stack **stack_b);
void		ft_position(t_stack **stack);
int			ft_len(const char *str, char c);
int			ft_lowst_index_pos(t_stack **stack);
void		ft_get_targ_pos(t_stack **a, t_stack **b);

//parsing utils
char		**ft_split(char *s, char c);
int			ft_atoi(const char *str);
int			ft_strlen(char *str);
char		*ft_strnstr(const char *big, const char *little, size_t len);
void		ft_free_matrix(char **matrix);

#endif