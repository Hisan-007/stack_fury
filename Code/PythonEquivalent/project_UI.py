import time
# ** HELPER METHODS ** #
def crux(w):
    set_w = list(set(w))
    set_w.sort()
    a = []
    for i in set_w:
        
        a.append([i,w.count(i)])
    return a

def count_the_websites(url, arr):
    count = 0
    for i in arr:
        if i == url:
            count+=1
    return count

#to get only the counts of individual websites
def give_counts(c):
    temp = [x[1] for x in c]
    return temp
    
#gives all websites for keywords
def give_all_websites(kw):
    #f = give_f()
    w= []
    for i in kw:
        temp = give_websites(i)
        try:
            w+=temp
        except:
            print('empty for:',i)
    return w

#gives websites for only a single word;
#sub function
def give_websites(word):
    for i in f:
        if i[0] == word:
            
            temp = list(set(i[1]))
            temp = [x for x in temp if len(x)!=0]
            temp.sort()
            return temp;

#give our main keywords_url objects      
def give_f():
    file = open("final_data_bank.txt", "r", encoding="utf-8")
    data = file.read().split('\n')
    file.close()
    answer = [x.split(' ') for x in data]
    f = [ [x[0], x[1::]] for x in answer]
    return f

#extract keywords only from text
def give_keywords(arr, stop_words):
    ans = []
    for i in arr:
        if i not in stop_words:
            ans.append(i)
    return list(set(ans))

def search(kw, c):
    count = max(give_counts(c))
    #print(count)
    limit = 7
    final_answer = ""
    for i in c:
        if i[1] == count:
            
                        final_answer+=i[0]+"\n"
    if(final_answer.count("\n")<3):
        for i in c:
            if i[1] == count-1:
                final_answer+=i[0]+"\n"
    return final_answer

file = open("stop_words.txt","r")
stop_words = file.read().split('\n')
file.close()
def google():
    text = q_text.get()
    text = text.lower()
    start = time.time()
    kw = give_keywords(text.split(' '), stop_words)

    #f = give_f()
    w = give_all_websites(kw)
    #print(len(w))
    c = crux(w)
    
    #print(search(kw,c))
    end = time.time()
    result.delete('1.0', END)
    answer = search(kw,c)
    result.insert(END, answer)
    time_label.config(text = str(answer.count("\n")+1) + " results in "+str(end-start)+" seconds")
    

f = give_f()

from tkinter import *
root = Tk()
root.iconbitmap(default='logo.ico')
root.title("StackFury")
root.geometry('800x700')

q_text = StringVar()

heading = Label(root, text = "STACK FURY", font=('Papyrus', 20))
heading.place(x = 250, y = 25)

question = Entry(root, textvariable = q_text)
question.configure(width = 45, font =('Calibri',20))
question.place(x = 50, y = 100)

search_button = Button(root, text="Search", font = ('Calibri', 15), command = google)
search_button.place(x = 700, y = 100)

result = Text(root, width = 70, font = ('Calibri',13), height = 16)
result.place(x = 50, y = 150)

time_label = Label(root, font = ("Calibri",13))
time_label.place(x = 50, y = 500)
root.mainloop()

