/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:53:07 by abdait-m          #+#    #+#             */
/*   Updated: 2020/12/20 06:31:21 by abdait-m         ###   ########.fr       */
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
                    used[(unsigned char)argv[i][j]] = 1;
                    write(1, &argv[i][j], 1);
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}