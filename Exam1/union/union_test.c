/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:47:25 by abdait-m          #+#    #+#             */
/*   Updated: 2020/12/28 15:15:46 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int used[255];
    int i, j;

    if (argc == 3)
    {
        i = 0;
        while (i < 255)
            used[i++] = 0;
        i = 1;
        while (i < 3)
        {
            j = 0;
            while (argv[i][j])
            {
                if (!used[(unsigned char)argv[i][j]])
                {
                    write(1, &argv[i][j], 1);
                    used[(unsigned char)argv[i][j]] = 1;
                }
                j++;
            }

            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}