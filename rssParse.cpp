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
			if (this->_rss->_nbItem > 10)
			  {
			    delete this->_rss->_items[0];
			    this->_rss->_nbItem = 0;
			  }
			this->_rss->_items[this->_rss->_nbItem++] = new item();
			this->_isItem = true;
		      }
		  }	
	      }
	    else
	      {
		if (split[i] == "\\item")
		  _isItem = false;
		else if (split[i] == "title")
		  this->_rss->_items[this->_rss->_nbItem - 1]->setTitle(split[i+1]);
		else if (split[i] == "description")
		  this->_rss->_items[this->_rss->_nbItem - 1]->setDescription(split[i+1]);
		else if (split[i] == "link")
		  this->_rss->_items[this->_rss->_nbItem - 1]->setLink(split[i+1]);
		else if (split[i] == "pubDate")
		  this->_rss->_items[this->_rss->_nbItem - 1]->setPubDate(split[i+1]);
		else if (split[i] == "author")
		  this->_rss->_items[this->_rss->_nbItem - 1]->setAuthor(split[i+1]);
		else if (split[i] == "category")
		  this->_rss->_items[this->_rss->_nbItem - 1]->setCategory(split[i+1]);
		else if (split[i] == "comments")
		  this->_rss->_items[this->_rss->_nbItem - 1]->setComments(split[i+1]);
	      }
	}
    }
  ifs.close();
}
