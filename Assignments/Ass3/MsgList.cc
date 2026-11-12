#include "MsgList.h"

MsgList::MsgList() : head(NULL), size(0) { }

MsgList::~MsgList()
{
  Node* curr = head;
  Node* next = NULL;

  while (curr != NULL) {
    next = curr->next;
    delete curr;
    curr = next;
  }
}

int MsgList::getSize() { return size; }

void MsgList::add(Msg* msg)
{
  if (msg == NULL)
    return;

  Node* newNode = new Node;
  newNode->data = msg;
  newNode->prev = NULL;
  newNode->next = NULL;

  Node* curr = head;
  Node* prev = NULL;

  while (curr != NULL && !msg->greaterThan(curr->data)) {
    prev = curr;
    curr = curr->next;
  }

  newNode->prev = prev;
  newNode->next = curr;

  if (prev == NULL)
    head = newNode;
  else
    prev->next = newNode;

  if (curr != NULL)
    curr->prev = newNode;

  ++size;
}

void MsgList::copySubset(string phoneNum, MsgList& origList)
{
  Node* curr = origList.head;

  while (curr != NULL) {
    if (curr->data->getSrc() == phoneNum || curr->data->getDest() == phoneNum)
      add(curr->data);
    curr = curr->next;
  }
}

void MsgList::copySubset(string phoneNum, MsgList& origList, SubscriberType type)
{
  Node* curr = origList.head;

  while (curr != NULL) {
    if ((type == C_SENDER   && curr->data->getSrc()  == phoneNum) ||
        (type == C_RECEIVER && curr->data->getDest() == phoneNum))
      add(curr->data);
    curr = curr->next;
  }
}

void MsgList::cleanup()
{
  Node* curr = head;
  Node* next = NULL;

  while (curr != NULL) {
    next = curr->next;
    delete curr->data;
    delete curr;
    curr = next;
  }

  head = NULL;
  size = 0;
}

void MsgList::print()
{
  if (head == NULL) {
    cout<<"No messages."<<endl;
    return;
  }

  Node* curr = head;
  Node* last = NULL;

  cout<<"FORWARD:"<<endl;
  while (curr != NULL) {
    curr->data->print();
    last = curr;
    curr = curr->next;
  }

  cout<<"BACKWARD:"<<endl;
  curr = last;
  while (curr != NULL) {
    curr->data->print();
    curr = curr->prev;
  }
}
