package no.sonat.collector.influx;

import com.fasterxml.jackson.annotation.JsonCreator;
import com.fasterxml.jackson.annotation.JsonProperty;

import javax.validation.constraints.NotNull;

/**
 * @author sondre
 */
public class InfluxConfiguration {

    @NotNull
    public final String url;

    @NotNull
    public final String userName;

    @NotNull
    public final String password;

    @NotNull
    public final String database;

    @JsonCreator
    public InfluxConfiguration(@JsonProperty("url") final String url,
                               @JsonProperty("userName") final String userName,
                               @JsonProperty("password") final String password,
                               @JsonProperty("database") final String database) {
        this.url = url;
        this.userName = userName;
        this.password = password;
        this.database = database;
    }

}
