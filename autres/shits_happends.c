#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool	ft_Life(int shits, int appends, const bool dont_worry_be_happy)
{
	if (shits == appends)
	{
		bool	your_maximum;
		bool	be_hopefull;
		bool	deal_with_it;

		your_maximum =  true;
		be_hopefull = your_maximum;
		deal_with_it = be_hopefull;
		printf ("Show must go on !");
		return (deal_with_it);
	}
	else
		return (dont_worry_be_happy);
}

int	main()
{
	int		shits;
	int 	appends;
	bool	dont_worry_be_happy;

	shits = rand ();
	appends = rand ();
	dont_worry_be_happy = true;
	ft_Life(shits, appends, dont_worry_be_happy);
}