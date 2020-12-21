/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:53:07 by abdait-m          #+#    #+#             */
/*   Updated: 2020/12/21 21:01:00 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main(int argc, char **argv)
{
    int used[255];
    int i, j;

    // this inter program
    if (argc == 3)
    {
        i = 0;
        while (i < 255)
            used[i++] = 0;
        i = 2;
        while (i > 0)
        {
            j = 0;
            while (argv[i][j])
            {
                if (i == 2 && !used[(unsigned char)argv[i][j]])
                    used[(unsigned char)argv[i][j]] = 1;
                else if (i ==1 && used[(unsigned char)argv[i][j]] == 1)
                {
                    write(1, &argv[i][j], 1);
                    used[(unsigned char)argv[i][j]] = 2;
                }
                j++;
            }
            i--;
        }
    }
    write(1, "\n", 1);
    return (0);
}