#include "../includes/ft_avl.h"

int		main(void)
{
	int		i;
	int		data;
	int		size;
	int		range;
	int		count;
	int		input;
	t_tree	*root;
	t_tree	*node;

	count = 0;
	root = NULL;
	
	// Type size & range
	printf("size: ");
	scanf("%d", &size);
	printf("range: ");
	scanf("%d", &range);
	ft_println(1);

	// create node n times & insert node to tree
	i = -1;
	srand((unsigned int)time(NULL));
	while (++i < size)
	{
		data = rand() % range;
		node = ft_create_node(data);
		count += ft_insert_node(&root, node);
	}

	// check by print tree
	while (1)
	{
		printf("[1] PRE_ORDER [2] IN_ORDER [3] POST_ORDER [4] LEVEL [5] EXIT\n");
		printf(">>> ");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("PRE_ORDER: ");
			if (ft_print_tree(root, PRE_ORDER) == ABNORMAL)
				return (ABNORMAL);
		}
		else if (input == 2)
		{
				printf("IN_ORDER: ");
				if (ft_print_tree(root, IN_ORDER) == ABNORMAL)
					return (ABNORMAL);
		}
		else if (input == 3)
		{
				printf("POST_ORDER: ");
				if (ft_print_tree(root, POST_ORDER) == ABNORMAL)
					return (ABNORMAL);
		}
		else if (input == 4)
		{
				printf("LEVEL: ");
				if (ft_print_tree(root, LEVEL) == ABNORMAL)
					return (ABNORMAL);
		}
		else if (input == 5)
			break;
		ft_println(1);
		printf("Node Count: %d\n", count);
		ft_println(1);
	}
	// search node in tree
	while (1)
	{
		printf("Type node to find\n");
		printf(">>> ");
		scanf("%d", &input);
		ft_search_node(root, input);
	}
}