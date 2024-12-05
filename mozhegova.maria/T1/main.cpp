#include <strinput.hpp>
#include <cstring>

int main()
{
  while (!std::cin.eof()) 
  {
    char * str = nullptr;
    try
    {
      str = mozhegova::inputString(std::cin, '\n');
    }
    catch (const std::exception& e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
    if (str[0] == '\0')
    {
      delete[] str;
      continue;
    }

    double * num = nullptr;
    char * tok = std::strtok(str, " ");
    bool isRectangle = std::strcmp(tok, "RECTANGLE") == 0;
    bool isScale = std::strcmp(tok, "SCALE") == 0;
    if (isRectangle)
    {
      double arr[4] = {};
      num = arr;
    }
    for (size_t i = 0; tok != NULL; i++)
    {
      tok = std::strtok(NULL, " ");
      if (tok != NULL)
      {
        num[i] = std::atof(tok);
      }
    }
    if (isRectangle) {}
    if (isScale) {}
    delete[] str;
  }
}
