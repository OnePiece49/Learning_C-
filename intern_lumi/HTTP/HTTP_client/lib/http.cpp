#include "http.hpp"


void Http_Client:: init_string(struct Mystring *s) {
  s->len = 0;
  s->ptr = (char *)malloc(s->len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
  
}

size_t Http_Client:: writefunc(void *ptr, size_t size, size_t nmemb, struct Mystring *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = (char *)realloc(s->ptr, new_len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}

void Http_Client:: init_http_client(char *url) {
  struct Mystring s;
  init_string(&s);

  curl_handle = curl_easy_init();
  if(curl_handle) {
  int pulsedata = 70;
  int tempdata  = 35;

  char sendbuffer[100];
  snprintf(sendbuffer, sizeof(sendbuffer), "pulse=%d&temp=%d", pulsedata, tempdata);

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, sendbuffer);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION,  writefunc);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&s);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

   res = curl_easy_perform(curl_handle);
  // res = curl_easy_perform(curl_handle);

    printf("Start receive data\n");
    if(res != CURLE_OK) {
      fprintf(stderr, "error: %s\n", curl_easy_strerror(res));
    } else {
       printf("Size: %lu\n", (unsigned long)s.len);
       printf("Data: %s\n", s.ptr);
     }
    printf("Receive done\n");
    curl_easy_cleanup(curl_handle);
    free(s.ptr);
  }
}
