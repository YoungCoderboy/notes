# WHY?

- The barrier between consumer format and producer format
- The barrier between consumer protocol and producer protocol
- load is increase with each increasing connection between producer and consumer

- pulsar is middleware that accept the information from the producer
- consumer then source their data from the middleware, Pulsar

- Pulsar has two layers

1. Service Level (pulsar)
2. Storage Level

# Introduction

- pulsar is high performance, multi-tenant solution for server to server messaging.
- Pulsar guaranties the message delivery with persistent message storage provided by apache Bookkeeper
- Pulsar is build on `pub-sub` pattern. In this pattern producer publish the messages to topic and consumer will subscribe to those topic and send `ack` to broker when processing is finished.
- When Subscription is created, pulsar retains all the messages, even if consumer is disconnected.

## Acknowledgment

- A message acknowledgment is sent by a consumer to a broker after the consumer consumes a message successfully. Then, this consumed message will be permanently stored and deleted only after all the subscriptions have acknowledged it. An acknowledgment (ack) is Pulsar's way of knowing that the message can be deleted from the system. If you want to store the messages that have been acknowledged by a consumer, you need to configure the message retention policy.
- There are two way to ack the message

1. Begin Ack individually :With individual acknowledgment, the consumer acknowledges each message and sends an acknowledgment request to the broker.
2. Begin Ack cumulatively : With cumulative acknowledgment, the consumer only acknowledges the last message it received. All messages in the stream up to (and including) the provided message are not redelivered to that consumer.

- Note: Cumulative acknowledgment cannot be used in Shared or Key_shared subscription type, because Shared or Key_Shared subscription type involves multiple consumers which have access to the same subscription. In Shared and Key_Shared subscription types, messages should be acknowledged individually.

Pulsar offers four distinct subscription types, each dictating how a group of consumers interacts with a topic's message stream. A **subscription** is a durable, named cursor that tracks message consumption progress for a consumer group on a topic. Each unique subscription on a topic receives its own independent copy of all messages.

Here's a summary of the subscription types:

- **Exclusive Subscription:**

  - **Concept:** A single, dedicated consumer pipeline.
  - **Topic Interaction:** Maintains its own independent cursor; receives _all_ messages from the topic.
  - **Extra:** Only **one consumer** allowed at a time. Guarantees **strict global ordering**. Ideal for highly sensitive, single-threaded processing.

- **Failover Subscription:**

  - **Concept:** A highly-available, single-active-consumer pipeline.
  - **Topic Interaction:** Maintains its own independent cursor; receives _all_ messages from the topic.
  - **Extra:** Multiple consumers can connect, but only **one is active (primary)**; others are hot standbys. Provides **automatic failover** and guarantees **strict global ordering**. Perfect for critical, ordered workflows requiring high availability.

- **Shared Subscription:**

  - **Concept:** A load-balanced pipeline for parallel consumption.
  - **Topic Interaction:** Maintains its own independent cursor; receives _all_ messages from the topic.
  - **Extra:** **Multiple consumers** actively consume in parallel. Messages are distributed via **round-robin** (or similar load-balancing). **No global ordering guarantee**. Suited for high-throughput, stateless work queues.

- **Key_Shared Subscription:**
  - **Concept:** A smartly load-balanced pipeline guaranteeing order _per-key_.
  - **Topic Interaction:** Maintains its own independent cursor; receives _all_ messages from the topic.
  - **Extra:** **Multiple consumers** actively consume in parallel. Messages distributed based on their **message key**; all messages for the same key go to the same consumer. Guarantees **per-key ordering**. Requires producers to set a message key. Ideal for stateful stream processing where related events must be processed in order while enabling overall parallelism.

In summary, to achieve a "fan-out" pattern where multiple independent consumer groups each receive _all_ messages from a single topic and process them in parallel (within their group), you create a **separate, distinct subscription for each consumer group**. Within each group, you then choose the appropriate subscription type (`Shared`, `Key_Shared`, `Failover`, or `Exclusive`) to define how messages are distributed and ordered among that group's consumers.
Here's a concise summary of Pulsar subscription types, tailored for your notes, emphasizing the relationship between Topic, Subscription, and other key elements:

## Apache Pulsar Subscription Types: A Summary

In Apache Pulsar, a **Subscription** is a **named, durable cursor** that defines how a group of **Consumers** interacts with a **Topic's** message stream. Each unique subscription on a topic receives a _complete, independent copy_ of all messages published to that topic.

### 1. Exclusive Subscription

- **Subscription Role:** A dedicated, single-consumer pipeline.
- **Topic Interaction:** Maintains its own independent cursor on the topic's full message log.
- **Extra Things:**
  - **Consumers:** Only **one active consumer** is allowed per subscription. Attempts by others to connect are rejected (or the existing one is disconnected).
  - **Ordering:** **Strict global ordering** of messages is guaranteed.
  - **Use Case:** Critical, highly-ordered processing, where only one instance should handle the stream.

### 2. Failover Subscription

- **Subscription Role:** A highly-available, single-active-consumer pipeline.
- **Topic Interaction:** Maintains its own independent cursor on the topic's full message log.
- **Extra Things:**
  - **Consumers:** Multiple consumers can connect, but only **one is primary (active)**; others are hot standbys.
  - **Ordering:** **Strict global ordering** is guaranteed, as only one consumer is active at a time.
  - **Failover:** Automatic promotion of a standby consumer if the primary fails, ensuring continuous, ordered consumption.
  - **Use Case:** High-availability scenarios requiring strict global message ordering with minimal downtime.

### 3. Shared Subscription

- **Subscription Role:** A load-balanced pipeline for parallel consumption.
- **Topic Interaction:** Maintains its own independent cursor on the topic's full message log.
- **Extra Things:**
  - **Consumers:** **Multiple consumers** can connect and actively consume in parallel.
  - **Message Distribution:** Messages are distributed **round-robin** (or similar load-balancing) among active consumers. Each message is delivered to only one consumer within the subscription.
  - **Ordering:** **No global ordering guarantee** (messages may be processed out of publish order across different consumers).
  - **Use Case:** High-throughput work queues where order across the entire stream is not critical (e.g., stateless task processing).

### 4. Key_Shared Subscription

- **Subscription Role:** A smartly load-balanced pipeline guaranteeing ordering per-key while enabling parallelism.
- **Topic Interaction:** Maintains its own independent cursor on the topic's full message log.
- **Extra Things:**
  - **Consumers:** **Multiple consumers** can connect and actively consume in parallel.
  - **Message Distribution:** Messages are distributed based on their **message key**. All messages with the _same key_ are guaranteed to be delivered to the _same consumer_ (in order). Messages with different keys go to different consumers.
  - **Ordering:** **Guaranteed ordering per-key.** Global ordering is not guaranteed.
  - **Requirement:** Messages _must_ have a key set by the producer.
  - **Use Case:** Stateful stream processing, where related events (e.g., all actions for a specific user) need ordered processing, but different groups of events can be processed in parallel.

---

**Key Takeaway for Fan-Out:**

To achieve a "fan-out" pattern (where multiple, independent applications/consumer groups each receive _all_ messages from a single topic and process them in parallel), you must create a **separate, distinct subscription for each application/group**. Within each of these unique subscriptions, you then choose the appropriate type (`Exclusive`, `Failover`, `Shared`, or `Key_Shared`) based on the specific ordering and parallelism needs of that particular consumer group.
