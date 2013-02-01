#include		"BrainReal.hpp"

BrainReal::BrainReal(gdl::Keys::Key tab[])
{
  for (unsigned u = 0; u < NB_KEYS; ++u)
    _key[u] = tab[u];
}

IBrain::eAction			BrainReal::action(gdl::Input& input, int* x, int* y)
{
  if (!(*x = input.isKeyDown(_key[RIGHT]) ? 1 : input.isKeyDown(_key[LEFT]) ? -1 : 0))
    *y = input.isKeyDown(_key[UP])    ? 1 : input.isKeyDown(_key[DOWN]) ? -1 : 0;
  else
    *y = 0;

  if (input.isKeyDown(_key[BOMB]))
    return ATTACK;
  if (!*x && !*y)
    return WAIT;
  return MOVE;
}
