#include "../../includes/push_swap.h"

static char	*ft_substr(char const *s, int start, int len)
{
    char	*substr;
    int		i;

    if (!s || !(substr = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}

int	count_words(char const *s, char c)
{
    int	count;
    int	i;

    count = 0;
    i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

static char	**process_words(char const *s, char c, char **split, int words)
{
    int	i;
    int	j;
    int	start;

    i = 0;
    j = 0;
    while (j < words)
    {
        while (s[i] == c)
            i++;
        start = i;
        while (s[i] && s[i] != c)
            i++;
        split[j] = ft_substr(s, start, i - start);
        if (!split[j])
        {
            while (j > 0)
                free(split[--j]);
            free(split);
            return (NULL);
        }
        j++;
    }
    split[j] = NULL;
    return (split);
}

char	**ft_split(char const *s, char c)
{
    char	**split;
    int		words;

    if (!s)
        return (NULL);
    words = count_words(s, c);
    split = malloc(sizeof(char *) * (words + 1));
    if (!split)
        return (NULL);
    return (process_words(s, c, split, words));
}

void	free_split(char **split)
{
    int	i;

    i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
}
