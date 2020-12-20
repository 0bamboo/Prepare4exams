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
    int mamenk[255];
    int mamenkawa, izmamenk;

    if (argc == 3)
    {
        mamenkawa = 0;
        while (mamenkawa < 255)
            mamenk[mamenkawa++] = 0;
        mamenkawa = 2;
        while (mamenkawa < 3)
        {
            izmamenk = 0;
            while (argv[mamenkawa][izmamenk])
            {
                if (mamenkawa == 2 && !mamenk[(unsigned char)argv[mamenkawa][izmamenk]])
                    mamenk[(unsigned char)[mamenkawa][izmamenk]] = 1;
                else if (mamenkawa == 1 && mamenk[(unsigned char)argv[mamenkawa][izmamenk]] == 1)
                {
                    write(1, &argv[mamenkawa][izmamenk], 1);
                    mamenk[(unsigned char)argv[mamenkawa][izmamenk]] = 2;
                }
                izmamenk++;
            }
            mamenkawa--;
        }
    }
    write(1, "\n", 1);
    return (0);
}