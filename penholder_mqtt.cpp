#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"
#include "greetings.hpp"

using namespace std;

#define ADDRESS     "tcp://sexy.mqttserver.org:1883"
#define CLIENTID    "pandora"
#define TOPIC       "/living_room/mqtt_topic/announcement"
#define QOS         1
#define TIMEOUT     10000L
const string mqtt_username = "mqtt_server_username";
const string mqtt_password = "mqtt_server_password";
string PAYLOAD;

int main(int argc, char* argv[])
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.username = &mqtt_username[0];
    conn_opts.password = &mqtt_password[0];

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    
    PAYLOAD = greetings_rand() + " " + now_date(ltm) + "!";
    pubmsg.payload = &PAYLOAD[0];
    
    pubmsg.payloadlen = PAYLOAD.length();
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), PAYLOAD, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}
