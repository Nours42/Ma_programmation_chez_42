/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend of code and magic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:31:51 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/05 13:31:55 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 typedef struct s_player
 {
    int     health;
    int     mana;
    int     deck;
    int     rune;
    int     draw;
    int     health_change;
 }              t_player;

typedef struct  s_oppo
{
    int     opp_hand;
    int     opp_actions;
    char    card_number_and_action[21];
}               t_oppo;

 typedef struct s_card
 {
    int     card_number;
    int     instance_id;
    int     location;
    int     card_type;
    int     cost;
    int     attack;
    int     defense;
    char    abilities[7];
    int     card_draw;
 }              t_card;

 typedef struct s_deck
 {
    int             card_id;
    struct s_card   *cards;
 }              t_deck;

int main()
{
    t_player    me;
    t_player    op;
    t_oppo      oppo;
    t_card      card;
    t_deck      deck;
    int         i;
    int         card_count;

    // game loop
    while (1) {
        scanf("%d%d%d%d%d", &me.health, &me.mana, &me.deck, &me.rune, &me.draw);
        //fprintf(stderr, "ME :\n health : %d\nmana : %d\ndeck : %d\nrune : %d\ndraw : %d\n\n", me.health, me.mana, me.deck, me.rune, me.draw);
        scanf("%d%d%d%d%d", &op.health, &op.mana, &op.deck, &op.rune, &op.draw);
        //fprintf(stderr, "OP :\n health : %d\nmana : %d\ndeck : %d\nrune : %d\ndraw : %d\n\n", op.health, op.mana, op.deck, op.rune, op.draw);
        scanf("%d%d", &oppo.opp_hand, &oppo.opp_actions); fgetc(stdin);
        //fprintf(stderr, "OPPO :\nopp_hand : %d\nopp_actions : %d\n\n", oppo.opp_hand, oppo.opp_actions);
        i = 0;
        while (i++ < oppo.opp_actions)
            scanf("%[^\n]", oppo.card_number_and_action); fgetc(stdin);
        scanf("%d", &card_count);
        //fprintf(stderr, "CARD COUNT :\ncard_count : %d\n\n", card_count);
        i = 0;
        while (i < card_count)
        {
            deck.card_id = i;
            scanf("%d%d%d%d%d%d%d%s%d%d%d", &card.card_number, &card.instance_id, &card.location, &card.card_type, &card.cost, &card.attack, &card.defense, card.abilities, &me.health_change, &op.health_change, &card.card_draw);
            //fprintf(stderr, "CARD : \ncard_number : %d\ninstance_id : %d\nlocation : %d\ncard_type : %d\ncost : %d\nattack : %d\ndefense : %d\nabilities : %s\nmy_health_change : %d\nopponent_health_change : %d\ncard_draw : %d\n\n", card.card_number, card.instance_id, card.location, card.card_type, card.cost, card.attack, card.defense, card.abilities, me.health_change, op.health_change, card.card_draw);
            i++;
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
    
        printf("PASS\n");
    }

    return 0;