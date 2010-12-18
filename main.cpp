#include <iostream>
#include "rssParse.h"

int	main(int ac, char **av)
{
  rssParse *test = new rssParse(std::string(av[1]));
  test->parse();

  std::cout << "title :"<< test->_rss->getTitle() << std::endl;
  std::cout << "description :"<< test->_rss->getDescription() << std::endl;
  std::cout << "lastBuiltDate :"<< test->_rss->getLastBuildDate() << std::endl;
  std::cout << "link :"<< test->_rss->getLink() << std::endl;
  std::cout << "item :"<< std::endl;
  for (int i = 0; i < test->_rss->_items.size(); i++)
    {
      std::cout << test->_rss->_items[i]->getTitle() << std::endl;
      std::cout << test->_rss->_items[i]->getDescription() << std::endl;
      std::cout << test->_rss->_items[i]->getPubDate() << std::endl;
      std::cout << test->_rss->_items[i]->getLink() << std::endl;
    }
}
