#include "recursionfunc.hpp"
#include <iostream>

const char * mozhegova::isSymbol(const char * str, const char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

const char * mozhegova::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : nullptr;
}

const char * mozhegova::hasNumber(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
}

const char * mozhegova::hasIdentifier(const char * str)
{
  return mozhegova::hasLetter(str);
}

const char * mozhegova::hasUnsignedInt(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasNumber(str);
  if (auto continues = mozhegova::hasUnsignedInt(next))
  {
    return continues;
  }
  return next;
}

const char * mozhegova::hasFactor(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasUnsignedInt(str);
  if (next)
  {
    return next;
  }
  next = mozhegova::hasIdentifier(str);
  if (next)
  {
    return next;
  }
  next = mozhegova::isSymbol(str, '(');
  next = mozhegova::hasExpression(next);
  next = mozhegova::isSymbol(next, ')');
  return next;
}

const char * mozhegova::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasFactor(str);
  if (auto next2 = mozhegova::isSymbol(next, '*'))
  {
    if (auto continues = mozhegova::hasTerm(next2))
    {
      return continues;
    }
  }
  return next;
}

const char * mozhegova::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = mozhegova::hasTerm(str);
  if (auto next2 = mozhegova::isSymbol(next, '+'))
  {
    if (auto continues = mozhegova::hasExpression(next2))
    {
      return continues;
    }
  }
  else if (auto next2 = mozhegova::isSymbol(next, '-'))
  {
    if (auto continues = mozhegova::hasExpression(next2))
    {
      return continues;
    }
  }
  return next;
}

bool mozhegova::isExpression(const char * str)
{
  auto next = mozhegova::hasExpression(str);
  return next && (*next == '\0');
}