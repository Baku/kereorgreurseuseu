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

void	item::setTitle(Qstring title)
{
  this->_title = title;
}

void	item::setDescription(Qstring desc)
{
  this->_description = desc;
}

void	item::setLink(Qstring link)
{
  this->_link = link;
}

void	item::setPubDate(Qstring date)
{
  this->_pubDate = date;
}

void	item::setAuthor(Qstring author)
{
  this->_author = author;
}

void	item::setCategory(Qstring category)
{
  this->_category = category;
}

void	item::setComments(Qstring com)
{
  this->_comments = com;
}

Qstring	item::getTitle() const
{
  return this->_title;
}

Qstring	item::getDescription() const
{
  return this->_description;
}

Qstring	item::getLink() const
{
  return this->_link;
}

Qstring	item::getPubDate() const
{
  return this->_pubDate;
}

Qstring	item::getAuthor() const
{
  return this->_author;
}

Qstring	item::getCategory() const
{
  return this->_category;
}

Qstring	item::getComments() const
{
  return this->_comments;
}
