#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>


typedef struct {
    char  *strongDescription;
    char  *strongId;
    char  *weakDescription;
    char  *weakId;
}protocolList;


void parseStrong(xmlDocPtr doc, xmlNodePtr curr, protocolList *pList)
{
    xmlChar *content;
    int count = 0;
                
    curr = curr->xmlChildrenNode;
                            
    while(curr != NULL)
    {
        if(curr->type == XML_ELEMENT_NODE)
        {                       
                content = xmlNodeListGetString(doc, curr->xmlChildrenNode, 1);
                /*....*/
                if((xmlStrcmp(curr->name, (const xmlChar *)"description")))
                {
                    pList[count].strongDescription = (char *)content; 
                    xmlFree(content);
                    content = NULL;
                }
                curr = curr->next;
                
                if((xmlStrcmp(curr->name, (const xmlChar *)"id")))
                {
                    pList[count].strongId = (char *)content;
                    xmlFree(content);
                    content = NULL;
                }
                //printf("%s : %s\n",cur->name,content);
                //xmlFree(content);
                /*free(content);*/   /* windows */
                //content = NULL;
        }
        count++;
        curr = curr->next;
    }
                                                                                                                                                                        
}

void parseWeak (xmlDocPtr doc, xmlNodePtr curr, protocolList *pList)
{
    xmlChar *content;
    int count = 0;

    curr = curr->xmlChildrenNode;

    printf("passo 2\n");
    while (curr != NULL)
    {
        if(curr->type == XML_ELEMENT_NODE)
        {
            content = xmlNodeListGetString(doc, curr->xmlChildrenNode, 1);
    printf("passo 3\n");
            /*....*/
            if((xmlStrcmp(curr->name, (const xmlChar *)"description")))
            {
                pList[count].weakDescription = (char *)content;
                xmlFree(content);
                content = NULL;
            }
            curr = curr->next;

    printf("passo 4\n");
            if((xmlStrcmp(curr->name, (const xmlChar *)"id")))
            {
                printf("%s : %s\n",curr->name,content);
                //pList[count].weakId = (char *)content;
                xmlFree(content);
                content = NULL;
            }
    printf("passo 5\n");
            //xmlFree(content);
            //content = NULL;
        }
        curr = curr->next;
        count++;
    
    }
    
}

void xmldatatostruct (protocolList *pList, const char *filename)
{
   xmlDocPtr doc;
   xmlNodePtr curr;
   
   doc = xmlParseFile(filename);
   curr = xmlDocGetRootElement(doc);

   curr = curr->xmlChildrenNode;

   while (curr != NULL)
   {
        if((!xmlStrcmp(curr->name, (const xmlChar *)"strong")))
        {
            parseWeak(doc, curr, pList);
        }

        if((!xmlStrcmp(curr->name, (const xmlChar *)"weak")))
        {
            parseStrong(doc, curr, pList); 
        }
        curr = curr->next;
   }
   
   xmlFreeDoc(doc);
}


int main(int argc, char **argv)
{

    protocolList *plist = NULL;
    int count = 0;

    printf("passo 1\n");

    xmldatatostruct( plist, "protocols.xml");

    printf("passo 2\n");
    
    while (plist != NULL)
    {
        printf("plist->weakDescription: %s\n", plist[count].weakDescription); 
        printf("plist->weakId: %s\n", plist[count].weakId); 
        printf("plist->strongDescription: %s\n", plist[count].strongDescription); 
        printf("plist->strongId: %s\n", plist[count].strongId); 
    }
    return 0;
}

/*
int main()
{

    xmlDocPtr doc;
    xmlNodePtr cur;

    doc = xmlParseFile("protocols.xml");

    cur = xmlDocGetRootElement(doc);
                            
    //cur = cur->children;
    cur = cur->xmlChildrenNode;

    while(cur != NULL)
    {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"strong")))
        {                       
            parseDoc(doc,cur);
        }
        
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"weak")))
        {                       
            parseDoc(doc,cur);
        }

        cur = cur->next;
    }
                                                                                                                
    xmlFreeDoc(doc); 
return 0;
}
*/
