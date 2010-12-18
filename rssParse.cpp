#include <iostream>
#include <fstream>
#include "rssParse.h"

rssParse::rssParse(std::string name):_filename(name)
{
  _isItem = false;
}

rssParse::~rssParse()
{
}

std::vector<std::string>	rssParse::splitString(std::string src, std::string sep)
{
  std::vector<std::string>	dest;
  std::string			tmp;
  for (int i = 0; i < src.size() ;i++)
    {
      for (int j = 0; j < sep.size() ; j++)
	if (src[i] == sep[j])
	  {
	    dest.push_back(tmp);
	    tmp.erase();
	    i++;
	  }
      tmp += src[i];
    }
  return dest;
}

void	rssParse::parse()
{
  std::ifstream      ifs;
  item		     *tmpItem;

  ifs.open(_filename.c_str());
  if (!ifs.fail())
    {
      this->_rss = new rss();
      char buff[1024];
      while (!ifs.eof())
	{
	  ifs.getline(buff, 1024);
	  std::string tmpString(buff);
	  std::vector<std::string> split;
	  split = splitString(tmpString, std::string("<>"));
	  for (int i = 0; i < split.size(); i++)
	    if (split[i][0] != ' ' && split[i][0] != '\0')
	      {
		if (_isItem == false)
		  {
		    if (split[i] == "title")
		      this->_rss->setTitle(split[i+1]);
		    else if (split[i] == "description")
		      this->_rss->setDescription(split[i+1]);
		    else if (split[i] == "link")
		      this->_rss->setLink(split[i+1]);
		    else if (split[i] == "pubDate")
		      this->_rss->setPubDate(split[i+1]);
		    else if (split[i] == "lastBuildDate")
		      this->_rss->setLastBuildDate(split[i+1]);
		    else if (split[i] == "image")
		      this->_rss->setImage(split[i+1]);
		    else if (split[i] == "language")
		      this->_rss->setLanguage(split[i+1]);
		    else if (split[i] == "item")
		      {
			tmpItem = new item();
			this->_isItem = true;
		      }
		  }
		else
		  {
		    if (split[i] == "title")
		      tmpItem->setTitle(split[i+1]);
		    else if (split[i] == "description")
		      tmpItem->setDescription(split[i+1]);
		    else if (split[i] == "link")
		      tmpItem->setLink(split[i+1]);
		    else if (split[i] == "pubDate")
		      tmpItem->setPubDate(split[i+1]);
		    else if (split[i] == "author")
		      tmpItem->setAuthor(split[i+1]);
		    else if (split[i] == "category")
		      tmpItem->setCategory(split[i+1]);
		    else if (split[i] == "comments")
		      tmpItem->setComments(split[i+1]);
		    if (split[i] == "/item")
		      {
			this->_rss->_items.push_back(tmpItem);
			_isItem = false;
		      }
		  }
	      }
	}
      ifs.close();
    }
}
