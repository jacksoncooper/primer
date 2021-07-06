#include <iostream>
#include <set>
#include <string>

class Message;

class Folder
{
    public:

    Folder(const std::string &name) : name(name) { }
    Folder(const Folder &) = delete;
    Folder &operator=(const Folder &) = delete;

    void addMsg(Message *);
    void remMsg(Message *);

    std::string &which() {
        return name;
    }

    std::set<Message *> &open() {
        return messages;
    }

    private:

    std::string name;
    std::set<Message *> messages;
};

class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

    public:

    explicit Message(const std::string &str = "") :
        contents(str) { }

    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

    const std::string &read() {
        return contents;
    }

    const std::set<Folder *> &find() {
        return folders;
    };

    private:

    std::string contents;
    std::set<Folder *> folders;

    void add_to_folders(const Message &);
    void remove_from_folders();
};

void Folder::addMsg(Message *message) {
    messages.insert(message);
}

void Folder::remMsg(Message *message) {
    this ? std::cout << this -> which() : std::cout << "nullptr";
    std::cout << std::endl;
   
    std::cout << message << std::endl;
    std::cout << messages.size() << std::endl;
    
    std::set<Message *>::iterator maybe_message = messages.find(message);
    std::cout << (maybe_message == messages.end()) << std::endl;
    // std::cout << *maybe_message << std::endl;
    // messages.erase(message);
}

Message::Message(const Message &m) :
    contents(m.contents), folders(m.folders)
{
    add_to_folders(m);
}

Message &Message::operator=(const Message &rhs) {
    // We call remove_from_folders() before add_to_folders() to ensure that the
    // copy-assignment is safe if *this == rhs;
    remove_from_folders();

    contents = rhs.contents;
    folders = rhs.folders;

    // Okay to use *this instead of rhs here as well.
    add_to_folders(rhs);

    return *this;
}

Message::~Message() {
    remove_from_folders();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folders(const Message &m) {
    for (Folder *f : m.folders) f -> addMsg(this);
}

void Message::remove_from_folders() {
    for (Folder *f : folders) {
        f -> remMsg(this);
        std::cout << "unreachable" << std::endl;
    }
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;

    for (Folder *f : lhs.folders) f -> remMsg(&lhs);
    for (Folder *f : rhs.folders) f -> remMsg(&rhs);

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    for (Folder *f : lhs.folders) f -> addMsg(&lhs);
    for (Folder *f : rhs.folders) f -> addMsg(&rhs);
}

int main()
{
    Message greeting("Hello Charles. How does lunch at noon sound?");
    Message question("Morning Peterson. Any news on the mediation hold?");
    Message answer("Hello again Charles. Nothing from the courts yet.");
    Message repeat_greeting("But what about lunch Peterson?");

    Folder work("work");
    Folder personal("personal");

    greeting.save(personal);

    // question.save(work);
    // answer.save(work);

    // for (Message *message : work.open())
    //     std::cout << message -> read() << std::endl;
};
