#include "item.h"

item::item(): _title(""),
	      _description(""),
	      _link(""),
	      _pubDate(""),
	      _author(""),
	      _category(""),
	      _comments("")
{
}

item::~item()
{
}

void	item::setTitle(std::string title)
{
  this->_title = title;
}

void	item::setDescription(std::string desc)
{
  this->_description = desc;
}

void	item::setLink(std::string link)
{
  this->_link = link;
}

void	item::setPubDate(std::string date)
{
  this->_pubDate = date;
}

void	item::setAuthor(std::string author)
{
  this->_author = author;
}

void	item::setCategory(std::string category)
{
  this->_category = category;
}

void	item::setComments(std::string com)
{
  this->_comments = com;
}

std::string	item::getTitle() const
{
  return this->_title;
}

std::string	item::getDescription() const
{
  return this->_description;
}

std::string	item::getLink() const
{
  return this->_link;
}

std::string	item::getPubDate() const
{
  return this->_pubDate;
}

std::string	item::getAuthor() const
{
  return this->_author;
}

std::string	item::getCategory() const
{
  return this->_category;
}

std::string	item::getComments() const
{
  return this->_comments;
}
