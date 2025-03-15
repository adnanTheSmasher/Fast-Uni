#include <iostream>
#include <string>

using namespace std;


class Message {
private:
    string text;

public:

    Message(const string& msg) : text(msg) {}

 
    virtual string toString() const {
        return text;
    }

   
    void setText(const string& msg) {
        text = msg;
    }
};


class SMS : public Message {
private:
    string recipientContactNo; 

public:
    
    SMS(const string& msg, const string& contactNo) : Message(msg), recipientContactNo(contactNo) {}

    
    string getRecipientContactNo() const {
        return recipientContactNo;
    }

    void setRecipientContactNo(const string& contactNo) {
        recipientContactNo = contactNo;
    }

   
    string toString() const override {
        return "To: " + recipientContactNo + ", Message: " + Message::toString();
    }
};


class Email : public Message {
private:
    string sender;  
    string receiver; 
    string subject;  

public:
  
    Email(const string& msg, const string& sndr, const string& rcvr, const string& subj)
        : Message(msg), sender(sndr), receiver(rcvr), subject(subj) {}

 
    string getSender() const {
        return sender;
    }

    void setSender(const string& sndr) {
        sender = sndr;
    }

    string getReceiver() const {
        return receiver;
    }

    void setReceiver(const string& rcvr) {
        receiver = rcvr;
    }

    string getSubject() const {
        return subject;
    }

    void setSubject(const string& subj) {
        subject = subj;
    }

    
    string toString() const override {
        return "From: " + sender + ", To: " + receiver + ", Subject: " + subject + ", Message: " + Message::toString();
    }
};


bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    return messageObject.toString().find(keyword) != string::npos;
}


string encodeMessage(const string& message) {
    string encodedMessage = message;
    for (char& c : encodedMessage) {
        if (isalpha(c)) {
            if (c == 'Z') c = 'A';
            else if (c == 'z') c = 'a';
            else c++;
        }
    }
    return encodedMessage;
}


int main() {
    
    SMS sms("Hello, how are you?", "123-456-7890");
    cout << sms.toString() << endl;

 
    Email email("Meeting at 10 AM", "alice@example.com", "bob@example.com", "Meeting Reminder");
    cout << email.toString() << endl;

 
    string keyword = "Hello";
    cout << "Contains keyword '" << keyword << "': " << (ContainsKeyword(sms, keyword) ? "Yes" : "No") << endl;

    
    string originalMessage = "This is Java";
    string encodedMessage = encodeMessage(originalMessage);
    cout << "Original Message: " << originalMessage << endl;
    cout << "Encoded Message: " << encodedMessage << endl;

    return 0;
}