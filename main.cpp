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
  std::cout << "title :" << test->_rss->_items[0]->getTitle() << std::endl;
  std::cout << "desc :" << test->_rss->_items[0]->getDescription() << std::endl;
  std::cout << "pubdate :" << test->_rss->_items[0]->getPubDate() << std::endl;
  std::cout << "link :" << test->_rss->_items[0]->getLink() << std::endl;
}
